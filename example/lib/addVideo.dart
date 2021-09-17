import 'package:av380/av380.dart';
import 'package:flutter/material.dart';

class AddVideoPage extends StatefulWidget {
  const AddVideoPage({Key? key}) : super(key: key);

  @override
  _AddVideoPageState createState() => _AddVideoPageState();
}

class _AddVideoPageState extends State<AddVideoPage> {

  TextEditingController textController = TextEditingController(text: '47448062');


  // void getDeviceStatus() async {
  //   await AV380.getDeviceStatus(int.parse(textController.text));
  // }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('添加摄像头'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text('输入设备ID'),
            Container(
              margin: EdgeInsets.only(top: 30),
              width: MediaQuery.of(context).size.width * 0.8,
              child: TextField(
                controller: textController,
                keyboardType: TextInputType.phone,
                decoration: InputDecoration(
                  border: OutlineInputBorder()
                ),
              ),
            ),
            TextButton(onPressed: (){}, child: Text('下一步'))
          ],
        ),
      ),
    );
  }
}
