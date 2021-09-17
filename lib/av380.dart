import 'package:av380/widget/video_container.dart';
import 'package:flutter/services.dart';

class AV380 {
  static const MethodChannel _channel = const MethodChannel('av380');
  static const EventChannel _eventChannel = const EventChannel('av380_event');

  initEvent() {
    _eventChannel
        .receiveBroadcastStream()
        .listen((event) async {
      print(event);
    }, onError: (dynamic error) {
      print(error);
    },cancelOnError: true);
  }

  static setAccount(ILogin login) async {
    return await _channel.invokeMethod('setAccount', {
      "deviceID": login.deviceID,
      "deviceUser": login.deviceUser,
      "devicePwd": login.devicePwd,
    });
  }

  static getDeviceStatus(int id) async {
    return await _channel.invokeMethod('getDeviceStatus', id);
  }
}


