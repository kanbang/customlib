import QtQuick 1.1
import "../Test"
Rectangle{

    width: 400
    height: 262
    color:  '#000000'


    Image{
        id: move
        anchors.centerIn: parent
        source: "./image/lockscreen_call1.png"

        MouseArea{

        }
    }

    Image {
        id: hungup
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        source: "./image/lockscreen_call3.png"
    }

    Image {
        id: answer
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        source: "./image/lockscreen_call2.png"
    }
}
