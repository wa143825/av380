import Flutter
import UIKit

public class SwiftAv380Plugin: NSObject, FlutterPlugin {
  public static func register(with registrar: FlutterPluginRegistrar) {
    let channel = FlutterMethodChannel(name: "Av380View", binaryMessenger: registrar.messenger())
    let instance = SwiftAv380Plugin()
    registrar.addMethodCallDelegate(instance, channel: channel)

		registrar.register(PVfactory(messenger: registrar.messenger()), withId: "PVView")
  }

  public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
    result("iOS " + UIDevice.current.systemVersion)
  }
}
