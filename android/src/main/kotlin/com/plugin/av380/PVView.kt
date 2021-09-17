package com.plugin.av380
import android.app.Activity
import android.content.Context
import android.graphics.Bitmap
import android.graphics.Color
import android.os.Environment
import android.util.DisplayMetrics
import android.widget.LinearLayout
import android.widget.TextView
import com.example.hyfisheyepano.GLFisheyeView
import com.macrovideo.sdk.defines.Defines
import com.macrovideo.sdk.defines.ResultCode
import com.macrovideo.sdk.media.*
import com.macrovideo.sdk.objects.DeviceInfo
import com.macrovideo.sdk.objects.LoginParam
import com.macrovideo.sdk.tools.Functions
import io.flutter.plugin.common.BinaryMessenger
import io.flutter.plugin.common.MethodCall
import io.flutter.plugin.common.MethodChannel
import io.flutter.plugin.common.MethodChannel.Result
import io.flutter.plugin.platform.PlatformView
import java.io.File
import java.io.FileOutputStream



class PVView (
	context: Context,
	messenger: BinaryMessenger,
	viewId: Int,
	args: Map<String, Any>?
): PlatformView, MethodChannel.MethodCallHandler, Activity() {
	private var ctx: Context = context
	private var methodChannel: MethodChannel = MethodChannel(messenger, "Av380View")
	private var mPlayView: LinearLayout = LinearLayout(ctx)
	private var mNVPanoPlayer: NVPanoPlayer? = null
	private var mTextview: TextView = TextView(ctx)
	private lateinit var deviceInfo: DeviceInfo
	private var mbPTZ = false

	private var mScreenWidth = 0 // 屏幕宽
	private var mScreenHeight = 0 // 屏幕高

	// 获取图像
	private var bm: Bitmap? = null

	data class ILogin(
		var deviceID: Int?,
		var deviceUser: String?,
		var devicePwd: String?
	)

	override fun onMethodCall(call: MethodCall, result: Result) {
		when(call.method) {
			"startPlay" -> {
				val args = ILogin(
					call.argument("deviceID"),
					call.argument("deviceUser"),
					call.argument("devicePwd")
				)
				login(args)
			}

			"stopPlay" -> {
				stopPlay(result)
			}

			"moveView" -> {
				val arg = call.argument<String>("direction")
				setMoveView(arg)
			}

			else -> result.notImplemented()

		}
	}

	init {
		args?.let {
			mTextview.text = it["text"] as String
		}
		print(viewId)
		methodChannel.setMethodCallHandler(this)

		val dm: DisplayMetrics = context.resources.displayMetrics
		mScreenWidth = dm.widthPixels
		mScreenHeight = dm.heightPixels
		
		initGLViewPlayer()
	}

	private fun initGLViewPlayer() {
		mPlayView.setBackgroundColor(Color.rgb(100,200, 100))
		val lp = LinearLayout.LayoutParams(mScreenHeight,mScreenWidth)
		mPlayView.layoutParams = lp
		if(mNVPanoPlayer == null) {
			mNVPanoPlayer = NVPanoPlayer(ctx, false)
			println("初始化成功: $mNVPanoPlayer")
			mNVPanoPlayer?.setHWDecodeStatus(false, false)
			val fishEyeView = GLFisheyeView(ctx)
			fishEyeView.setMode(NVPanoPlayer.PANO_PLAY_MODE_13)
			mNVPanoPlayer?.setGlFishView(fishEyeView)
			mPlayView.addView(mNVPanoPlayer?.glFisheyeView)
			LibContext.SetContext(mNVPanoPlayer, null, null, null)
		}
	}

	// 登陆
	private fun login(args: ILogin) {
		val deviceID = args.deviceID ?: 0
		val deviceUser = args.deviceUser
		val devicePwd = args.devicePwd

		if(args.deviceID != null) {
			deviceInfo = DeviceInfo(
				Defines._nDeviceID,
				deviceID,
				deviceID.toString(),
				Defines.AP_MODE_IP,
				Defines._nMRPort,
				deviceUser,
				devicePwd,
				"ABC",
				"${deviceID}${Defines.MV_DOMAIN_SUFFIX}",
				Defines.SERVER_SAVE_TYPE_ADD
			)
		}

		val loginParam = LoginParam(deviceInfo, Defines.LOGIN_FOR_PLAY)

		LoginHelper.loginDevice(ctx, loginParam) {
			if (it != null && it.getnResult() == ResultCode.RESULT_CODE_SUCCESS) {
				println(it.getnResult())
				val camType: Int = it.camType
				if(camType == 0) {
					mbPTZ = it.isbPTZ()
					startPlay(it)
				}
			} else if(it != null) {
				print(it.getnResult())
			} else {
				println(ResultCode.RESULT_CODE_FAIL_SERVER_CONNECT_FAIL)
			}
		}
	}

	private fun startPlay(args: LoginHandle) {
		mNVPanoPlayer?.setnServerID(args.getnDeviceID())
		Player.setPlaying(Player.CurrentSelPlayer(), true)
		mNVPanoPlayer?.EnableRender()
		val hasStartPlay = mNVPanoPlayer?.startPlay(0, 0, 0, false, args)
		println("setMoveView: $hasStartPlay")
	}

	private fun stopPlay(result: Result) {
		bm = mNVPanoPlayer?.screenShot()
		if(bm != null) {
			val image: Bitmap = Functions.zoomBitmap(bm, 320, 240)
			val file = File(Environment.getExternalStorageDirectory().toString() + File.separator + "zxp/")
			val mk = file.mkdirs()
			println(mk)

			val imageFile = File(file.absolutePath + File.separator + "demo.jpg")
			val out = FileOutputStream(imageFile)
			image.compress(Bitmap.CompressFormat.JPEG, 90, out)
			out.flush()
			out.close()
			result.success(imageFile.absolutePath)
		}
		result.success(null)
		mNVPanoPlayer?.stopPlay()
	}


	private fun setMoveView(event: String?) {
		var left = false
		var right = false
		var up = false
		var down = false
		when(event) {
			"left" -> left = true
			"right" -> right = true
			"up" -> up = true
			"down" -> down = true
		}
		mNVPanoPlayer?.setPTZAction(left, right, up, down, 5)
	}


	override fun getView(): LinearLayout {
		return mPlayView
	}

	override fun dispose() {

	}
}
