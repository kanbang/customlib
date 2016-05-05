// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Column {
    spacing: 2

    Rectangle { color: "red"; width: 50; height: 50 }
    Rectangle { id: greenRect; color: "green"; width: 20; height: 50 }
    Rectangle { color: "blue"; width: 50; height: 20 }

    // 当把 greenRect 的visible 设为false 后，后面的矩形的位置就要发生改变了。
    // 下面这个就是把修改的值延长
    move: Transition {
        NumberAnimation { properties: "x,y"; duration: 1000 }
    }

    Row {

        anchors.horizontalCenter: parent.horizontalCenter
        Rectangle {
            color: "black"
            width: 50
            height: 50
        }

        Rectangle {
            color: "lightblue"
            width: 50
            height: 50
        }

        Column {
            Rectangle {
                color: "lightGreen"
                width: 50
                height: 50
            }

            Rectangle {
                color: "red"
                width: 50
                height: 50
            }
        }
    }

    focus: true
    Keys.onSpacePressed: greenRect.visible = !greenRect.visible
}
