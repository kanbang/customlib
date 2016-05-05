// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

/**
  子组件可以依赖父组件的属性,即可以是子组件的属性跟父组件的属性绑定在一起,
  当父组件的属性改变的时候,子组件也跟着改变,但是不能用父组件的属性跟子组件的
  属性绑定在一起.因为这时,子组件还没有创建.
  */
Rectangle {
    id: root
    width: 300
    height: 300

    color: "lightblue"

    Rectangle {
        id: one
        anchors.centerIn: parent
        width:  200
        height: 200
        visible : false

        color: "red"
        Rectangle{
            id: two
            width: 100
            height: 100
            visible : one.visible

            color: "green"
        }

        Image {
            id: image;
            anchors.fill: parent
            source: "./SmartHome/pics/icons/light_on.png" }
    }

    MouseArea{
        anchors.fill:  parent

        onClicked: {
            one.visible = !one.visible;
            console.log("log ", image.source);s
        }
    }
}
