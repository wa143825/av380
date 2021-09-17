//
//  PVfactory.swift
//  av380
//
//  Created by mac on 2021/7/3.
//

import Foundation
import Flutter


class PVfactory: NSObject,FlutterPlatformViewFactory {
		
		var messenger:FlutterBinaryMessenger
		
		init(messenger:FlutterBinaryMessenger) {
				self.messenger = messenger
				super.init()
		}
		
		func create(withFrame frame: CGRect, viewIdentifier viewId: Int64, arguments args: Any?) -> FlutterPlatformView {
				return PVView(frame, viewID: viewId,args: args, messenger: messenger)
		}
		
		func createArgsCodec() -> FlutterMessageCodec & NSObjectProtocol {
				return FlutterStandardMessageCodec.sharedInstance()
		}
}
