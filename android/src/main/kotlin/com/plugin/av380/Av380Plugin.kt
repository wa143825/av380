package com.plugin.av380
import android.Manifest
import android.app.Activity
import android.content.Context
import android.content.pm.PackageManager
import android.util.Log
import androidx.annotation.NonNull
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat


import io.flutter.embedding.engine.plugins.FlutterPlugin
import io.flutter.embedding.engine.plugins.activity.ActivityAware
import io.flutter.embedding.engine.plugins.activity.ActivityPluginBinding
import io.flutter.plugin.common.*
import io.flutter.plugin.common.MethodChannel.MethodCallHandler
import io.flutter.plugin.common.MethodChannel.Result
import java.util.*

import com.macrovideo.sdk.media.*
import com.macrovideo.sdk.setting.DeviceConfigSetting
import com.macrovideo.sdk.objects.DeviceInfo
import com.macrovideo.sdk.defines.Defines
import com.macrovideo.sdk.defines.ResultCode
import com.macrovideo.sdk.objects.LoginParam

/** AV380Plugin */
class Av380Plugin: FlutterPlugin, MethodCallHandler, ActivityAware {
  private lateinit var channel : MethodChannel
  private lateinit var activity: Activity
  private lateinit var ctx: Context
  private lateinit var msg: BinaryMessenger
  private var eventSink: EventChannel.EventSink? = null

  override fun onAttachedToEngine(binding: FlutterPlugin.FlutterPluginBinding) {
    ctx = binding.applicationContext
    msg = binding.binaryMessenger
    channel = MethodChannel(msg, "av380")
    channel.setMethodCallHandler(this)
    binding.platformViewRegistry.registerViewFactory("PVView", PVFactory(msg))

    val eventChannel = EventChannel(msg, "av380_event")
    eventChannel.setStreamHandler(
      object : EventChannel.StreamHandler {
        override fun onListen(arguments: Any?, events: EventChannel.EventSink?) {
          eventSink = events
        }
        override fun onCancel(arguments: Any?) {
          eventSink = null
        }
      }
    )
//    checkPermission()
  }

  override fun onMethodCall( call: MethodCall, result: Result) {
    when (call.method) {
      "login" -> login(call.arguments as PVView.ILogin, result)
      "setAccount" -> {
        val args = PVView.ILogin(
          call.argument("deviceID"),
          call.argument("deviceUser"),
          call.argument("devicePwd")
        )
        setAccount(args)
      }
      "getDeviceStatus" -> getDeviceStatus(call.arguments as Int)
      else -> print("null")
    }
  }

  private fun login(args: PVView.ILogin, result: Result) {
    lateinit var  deviceInfo: DeviceInfo
    val deviceID = args.deviceID ?: 0
    val deviceUser = args.deviceUser
    val devicePwd = args.devicePwd

    if (args.deviceID != null) {
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
          result.success(it)
        }
      } else if(it != null) {
        print(it.getnResult())
      } else {
        println(ResultCode.RESULT_CODE_FAIL_SERVER_CONNECT_FAIL)
      }
    }
  }

  private fun setAccount(args: PVView.ILogin) {

    val deviceInfo = DeviceInfo(
      -1,
      args.deviceID ?: 0,
      args.deviceID.toString(),
      Defines.AP_MODE_IP,
      Defines._MRPort,
      args.deviceUser,
      args.devicePwd,
      "ABC",
      "${args.deviceID}${Defines.MV_DOMAIN_SUFFIX}",
      Defines.SERVER_SAVE_TYPE_ADD
    )

    deviceInfo.strPassword = "a123456"

    val loginParam = LoginParam(deviceInfo, Defines.LOGIN_FOR_PLAY)
    LoginHelper.loginDevice(ctx, loginParam) {
      println(it)

//      DeviceAccountSetting.setAccountConfig(deviceInfo, deviceUser, devicePwd, deviceID, it)
    }

  }

  private fun getDeviceStatus(id: Int) {
  }

  // 检查wifi权限
  private fun checkPermission() {
    val permissionArr = ArrayList<String>()
    // 存储图片时需要此权限
    val writeExtrnalStorage = ContextCompat.checkSelfPermission(ctx, Manifest.permission.WRITE_EXTERNAL_STORAGE)
    if (writeExtrnalStorage != PackageManager.PERMISSION_GRANTED) {
      permissionArr.add(Manifest.permission.WRITE_EXTERNAL_STORAGE)
    }
    if (permissionArr.size > 0) run {
      ActivityCompat.requestPermissions(activity, permissionArr.toTypedArray(), 100)
    }
  }

  override fun onDetachedFromEngine(@NonNull binding: FlutterPlugin.FlutterPluginBinding) {
    channel.setMethodCallHandler(null)
  }

  override fun onAttachedToActivity(binding: ActivityPluginBinding) {
    activity = binding.activity
  }

  override fun onDetachedFromActivityForConfigChanges() {
  }

  override fun onReattachedToActivityForConfigChanges(binding: ActivityPluginBinding) {
    activity = binding.activity
  }

  override fun onDetachedFromActivity() {

  }
}
