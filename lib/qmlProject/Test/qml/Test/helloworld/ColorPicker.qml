import QtQuick 1.1

/**
用组件来实现一个颜色块，然后在需要的时候使用这个组件就可以。
组件其实就和其他编程语言中的宏，函数，类，结构体等功能差不多，
代码复用

组件由一个单独的QML文件名组成，文件名总是以大写字母开头，
要使用该组件的时候，直接使用该文件名就可以了。

@Component的语法规则
定义了一个信号 cLicked1，则当这个信号发射的时候，用onCLicked1接收
onCLicked1：要调用的函数或者语句
*/
Item {
    id:container
    property alias cellColor:rectangle.color
    //在这个例子中，这个信号的参数没有用上
    signal cLicked1(color cellColor)
    width:40;height:25

    // 在Item中内嵌一个id为rectangle白边框的矩形区域，大小占满整个item

    Rectangle {
        id:rectangle
        border.color: "white"
        anchors.fill: parent
    }

    /**
    为Item增加了一块鼠标响应区，看它的anchors知道，在整个Item区域
    内都是鼠标活动区，都能侦听鼠标事件
    */
    MouseArea {
        anchors.fill: parent
        //为鼠标单机事件增加了一个处理行为，这里是发出了一个click()的信号，
        //这个信号是我们在Item里定义的那个signal。
        onClicked: container.cLicked1(container.cellColor)
    }
}

