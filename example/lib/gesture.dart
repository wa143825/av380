import 'package:flutter/material.dart';
import 'dart:math' as math;

class GesturePage extends StatefulWidget {
  const GesturePage({Key? key}) : super(key: key);

  @override
  _GesturePageState createState() => _GesturePageState();
}

class _GesturePageState extends State<GesturePage> {

  Offset startPoint = Offset(0, 0);
  Offset endPoint = Offset(0, 0);

  void _onPanStart(DragStartDetails details) {
    startPoint = details.localPosition;
  }

  void _onPanUpdate(DragUpdateDetails details) {
    endPoint = details.localPosition;
  }

  void _onPanEnd() {
    var angle = math.atan2(endPoint.dy - startPoint.dy, endPoint.dx - startPoint.dx) / math.pi * 180;
    if(angle < 0) {
      angle = 360 - angle.abs();
    }

    if(angle > 315 || angle < 45) {
      print("向右");
    }
    if(angle > 45 && angle < 135) {
      print("向下");
    }
    if(angle > 135 && angle < 225) {
      print("向左");
    }
    if(angle > 225 && angle < 315) {
      print("向上");
    }



    print(angle.toStringAsFixed(0));
  }


  String parserOffset(Offset offset){
    return '(${offset.dx.toStringAsFixed(2)},${offset.dy.toStringAsFixed(2)})';
  }

  @override
  Widget build(BuildContext context) {
    return WillPopScope(
      onWillPop: () async {
        Navigator.pop(context, '123');
        return false;
      },
      child: Scaffold(
        appBar: AppBar(title: Text('手势'),),
        body: Center(
          child: GestureDetector(
            onPanStart: (detail) => _onPanStart(detail),
            onPanUpdate: (detail) => _onPanUpdate(detail),
            onPanEnd: (detail) => _onPanEnd(),
            child: Container(height: 300, width: 300, color: Colors.blue,),
          ),
        )
      ),
    );
  }
}

