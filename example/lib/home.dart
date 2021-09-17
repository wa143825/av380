import 'package:av380/widget/video_container.dart';
import 'package:flutter/material.dart';
import 'package:av380/av380.dart';

class HomePage extends StatefulWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {

  String img = '';

  @override
  Widget build(BuildContext context) {

    double scrrenW = MediaQuery.of(context).size.width;

    return Scaffold(
      appBar: AppBar(
        title: Text('设备列表', style: TextStyle(color: Colors.black),),
        centerTitle: true,
        backgroundColor: Colors.white,
        actions: [
          IconButton(
              onPressed: () {
                Navigator.of(context).pushNamed('/addVideo').then((value) {});
              },
              icon: Icon(Icons.add_circle_outline, color: Colors.black,)
          )
        ],
      ),
      backgroundColor: Color(0xffF7F7F7),
      body: SingleChildScrollView(
        child: Column(
          children: [
            Container(
              decoration: BoxDecoration(
                color: Colors.white
              ),
              child: Column(
                children: [
                  Padding(
                    padding: EdgeInsets.all(15.0),
                    child: Row(
                      mainAxisAlignment: MainAxisAlignment.spaceBetween,
                      children: [
                        Row(
                          children: [
                            Container(
                              color: Color(0xff4099D8),
                              height: 20,
                              width: 5,
                              margin: EdgeInsets.only(right: 10),
                            ),
                            Text('办公室'),
                          ],
                        ),
                        Icon(Icons.storage)
                      ],
                    ),
                  ),
                  Container(
                    width: scrrenW,
                    height: scrrenW* 0.66,
                    decoration: BoxDecoration(
                      color: Color(0xff000000)
                    ),
                    child: DefaultTextStyle(
                      style: TextStyle(color: Colors.white),
                      child: Stack(
                        children: [
                          Positioned(
                            left: 10,
                            top: 10,
                            child: Text('ID:47448062'),
                          ),
                          Positioned(
                            right: 10,
                            top: 10,
                            child: Text('2021:03:26'),
                          ),
                          Positioned(
                            bottom: 10,
                            left: 10,
                            child: Text('互联网在线'),
                          ),
                          Center(
                            child: GestureDetector(
                              child: Icon(Icons.play_circle_fill, color: Colors.white, size: 80,),
                              onTap: () {
                                // AV380.setAccount(ILogin(47448062, 'admin', 'a12345'));
                                AV380.getDeviceStatus(47448062);
                                // Navigator.of(context).pushNamed('/video').then((value) {
                                //   print(value);
                                //   this.setState(() {
                                //     img = value as String;
                                //   });
                                // });
                              },
                            ),
                          ),
                        ],
                      ),
                    ),
                  ),
                ]
              ),
            ),
            // TextField(
            //   keyboardType: TextInputType.number,
            //   decoration: InputDecoration(
            //       labelText: '设备ID'
            //   ),
            // ),
            // TextField(
            //   decoration: InputDecoration(
            //       labelText: '账户'
            //   ),
            // ),
            // TextField(
            //   decoration: InputDecoration(
            //       labelText: '密码'
            //   ),
            // ),
            // Container(
            //   height: 240,
            //   width: 320,
            //   color: Colors.blue,
            //   child: Builder(builder: (ctx) {
            //     if(img.length != 0) {
            //       return Image.file(File(img));
            //     }
            //     return Container();
            //   },),
            // ),
            Row(
              children: [
                ElevatedButton(
                  onPressed: () {
                    Navigator.of(context).pushNamed('/video').then((value) {
                      print(value);
                      this.setState(() {
                        img = value as String;
                      });
                    });
                  },
                  child: Text('连接设备'),
                ),
                ElevatedButton(
                  onPressed: () async {
                    Navigator.of(context).pushNamed('/gesture').then((value) => print(value));
                  },
                  child: Text('手势页面'),
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}
