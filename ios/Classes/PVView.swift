//
//  PVView.swift
//  av380
//
//  Created by mac on 2021/7/3.
//

import Foundation
import Flutter
import mi_decoder_framework

class DataType {
	var deviceID: String?
	var deviceUser: String?
	var devicePwd: String?
}


class PVView: NSObject, FlutterPlatformView {
	private var channel: FlutterMethodChannel
	
	let label = UILabel()
	let playView = UIView()
	var mNVPanoPlayer:NVPanoPlayer
	let m_rectFull = UIScreen.main.bounds
	let nStreamType = STREAM_TYPE_HD
	
	
	init(_ frame: CGRect,viewID: Int64,args :Any?, messenger:FlutterBinaryMessenger) {
		self.channel = FlutterMethodChannel(name: "Av380View", binaryMessenger: messenger)
		mNVPanoPlayer = NVPanoPlayer(frame: playView.frame)
		mNVPanoPlayer.contentMode = .scaleAspectFill
		playView.frame = m_rectFull
		playView.addSubview(mNVPanoPlayer)
		super.init()
		
		if(args is NSDictionary) {
			let dict  = args as! NSDictionary
			label.text = dict.value(forKey: "text") as? String
		}
		
		channel.setMethodCallHandler { (call: FlutterMethodCall, result: FlutterResult) in
			var args = [String: Any]()
			if let arguments = call.arguments {
				args = arguments as! Dictionary<String, Any>
			}
			
			switch (call.method) {
				case "startPlay":
					self.login(args: args, result: result)
				case "stopPlay":
					self.stopPlay(result: result)
				case "moveView":
					self.moveView(args: args, result: result)
				default:
					result(FlutterMethodNotImplemented)
			}
		}
	}
	
	func login(args: Dictionary<String, Any>, result: FlutterResult) {
		
		let deviceID = args["deviceID"] as? Int32
		let deviceUser = args["deviceUser"] as? String
		let devicePwd = args["devicePwd"] as? String

			let dInfo = NVDevice()
			dInfo.strServer = "192.168.1.1"
			dInfo.nPort = 8800
			dInfo.strMacAddress = "ABC"
			dInfo.setDevID(deviceID!)
			dInfo.strUsername = deviceUser
			dInfo.strPassword = devicePwd
			dInfo.nAddType = ADD_TYPE_SYNC_FROM_NET
			dInfo.nConfigID = 1
			
			let param: LoginParam = LoginParam()
			param.device = dInfo
			param.connectionType = 0
			param.handler = { loginResult in
				DispatchQueue.main.async(execute: { [self] in
					self.startPlay(param: loginResult!)
				})
			}
		
			LoginHelper.loginDevice(param)
	}
	
	func startPlay(param: LoginHandle) {
		mNVPanoPlayer.frame = m_rectFull
		mNVPanoPlayer.startPlay(
			0,
			streamType: nStreamType,
			audio: true,
			loginHandel: param
		)
	}
	
	func stopPlay(result: FlutterResult) {
		let path: UIImage = mNVPanoPlayer.screenShot()
		let homedDirectory = NSHomeDirectory()+"/Documents/demo.jpg"
		let imgData = path.jpegData(compressionQuality: 0.8)
		do{
			try imgData?.write(to: URL(fileURLWithPath: homedDirectory))
		} catch {
			
		}
		
		mNVPanoPlayer.stopPlay()
		result(homedDirectory)
		
	}
	
	func moveView(args: Dictionary<String, Any?>, result: FlutterResult) {
		let direction:String = args["direction"] as! String
		var left = false
		var right = false
		var up = false
		var down = false
		switch direction {
			case "left" :
				left = true
			case "right" :
				right = true
			case "up" :
				up = true
			case "down" :
				down = true
			default: break
		}
		mNVPanoPlayer.setPTZActionLeft(left, right: right, up: up, down: down, step: 5)
	}
	
	deinit {
			channel.setMethodCallHandler(nil)
	}
	
	func view() -> UIView {
		return playView
	}
}
