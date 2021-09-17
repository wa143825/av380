import 'package:av380/widget/video_container.dart';
import 'package:flutter/material.dart';
import 'dart:math' as math;

import 'package:flutter/services.dart';

class VideoPage extends StatefulWidget {
  const VideoPage({Key? key}) : super(key: key);

  @override
  _VideoPageState createState() => _VideoPageState();
}

class _VideoPageState extends State<VideoPage> {

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
      VideoContainer.moveView(EMove.RIGHT);
    }
    if(angle > 45 && angle < 135) {
      VideoContainer.moveView(EMove.DOWN);
    }
    if(angle > 135 && angle < 225) {
      VideoContainer.moveView(EMove.LEFT);
    }
    if(angle > 225 && angle < 315) {
      VideoContainer.moveView(EMove.UP);
    }
  }


  @override
  void initState() {
    super.initState();
    SystemChrome.setPreferredOrientations([
      DeviceOrientation.landscapeLeft,
    ]);

  }

  @override
  void dispose() async {
    super.dispose();
    SystemChrome.setPreferredOrientations([
      DeviceOrientation.portraitUp,
    ]);
  }

  Future<bool> back() async {
    String? img =  await VideoContainer.stopPlay();
    print(img);
    if(img != null) {
      Navigator.pop(context, img);
      return false;
    }
    Navigator.pop(context, '');
    return true;
  }

  GlobalKey gk = GlobalKey();

  @override
  Widget build(BuildContext context) {
    return WillPopScope(
      onWillPop: () => back(),
      child: Scaffold(
        body: Stack(
          children: [
            GestureDetector(
              onPanStart: (detail) => _onPanStart(detail),
              onPanUpdate: (detail) => _onPanUpdate(detail),
              onPanEnd: (detail) => _onPanEnd(),
              child: Container(
                  color: Colors.cyan,
                  child: VideoContainer(key: gk, text: '从flutter传来的', )
              ),
            ),
            Positioned(
              left: 20,
              top: 20,
              child: IconButton(onPressed: () => back(), icon: Icon(Icons.arrow_back_ios, color: Colors.white,))
            )
          ],
        ),
      ),
    );
  }
}
