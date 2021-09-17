import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/services.dart';

class VideoContainer extends StatelessWidget {
  const VideoContainer({this.text = '',  Key? key}) : super(key: key);
  final String text;


  static const platform = MethodChannel('Av380View');
  static startPlay(ILogin login) {
    return platform.invokeMethod('startPlay', {
      "deviceID": login.deviceID,
      "deviceUser": login.deviceUser,
      "devicePwd": login.devicePwd,
    });
  }

  static stopPlay() {
    return platform.invokeMethod('stopPlay');
  }

  static moveView(EMove move) {
    switch(move) {
      case EMove.UP:
        return platform.invokeMethod('moveView', {"direction": "up"});
      case EMove.DOWN:
        return platform.invokeMethod('moveView', {"direction": "down"});
      case EMove.LEFT:
        return platform.invokeMethod('moveView', {"direction": "left"});
      case EMove.RIGHT:
        return platform.invokeMethod('moveView', {"direction": "right"});
    }
  }

  @override
  Widget build(BuildContext context) {
    if(defaultTargetPlatform == TargetPlatform.android) {
      return AndroidView(
        viewType: 'PVView',
        creationParams: {"text": text},
        creationParamsCodec: StandardMessageCodec(),
      );
    } else if(defaultTargetPlatform == TargetPlatform.iOS) {
      return UiKitView(
          viewType: 'PVView',
          creationParams: {"text": text},
          creationParamsCodec: StandardMessageCodec()
      );
    } else {
      return Text('不支持的平台');
    }
  }
}

enum EMove {
  UP,
  DOWN,
  LEFT,
  RIGHT
}

class ILogin {
  int deviceID;
  String deviceUser;
  String devicePwd;

  ILogin(this.deviceID,this.deviceUser,this.devicePwd);

  ILogin.fromJson(json) :
    deviceID = json["deviceID"],
    deviceUser = json["deviceUser"],
    devicePwd = json["devicePwd"];
}