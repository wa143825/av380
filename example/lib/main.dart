import 'package:av380_example/gesture.dart';
import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';

import 'video.dart';
import 'home.dart';
import 'addVideo.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {

    debugPaintSizeEnabled = false;

    return MaterialApp(
      routes: {
        "/addVideo": (BuildContext ctx) => AddVideoPage(),
        "/video": (BuildContext ctx) => VideoPage(),
        "/gesture": (BuildContext ctx) => GesturePage(),
      },
      home: HomePage(),
    );
  }
}