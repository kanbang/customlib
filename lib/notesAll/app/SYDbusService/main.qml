import QtQuick 1.1

Item {
    width: 400
    height: 400

    Connections {
        target: dbusservice
        onNotifyQMLDBusChanged:{
            showText.text = text
        }
    }

    TextEdit {
        id: textEdit
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 20
        anchors.leftMargin: 20

        width: 200
        height: 25

        font.pixelSize: 20
        text: qsTr("发送到client")

        Rectangle {
            anchors.fill: parent
            color: "lightblue"
            z:-1
        }
    }

    Text {
        anchors.top: textEdit.top
        anchors.left: textEdit.right
        anchors.leftMargin:  20

        width: 80
        height: 30

        color: "black"
        font.pixelSize: 25
        text: "biu ~!"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                dbusservice.sendDBus(textEdit.text)
            }
        }

        Rectangle {
            anchors.fill: parent
            color: "#909090"
            z:-1
            radius: 5
        }
    }

    Rectangle {
        anchors.top: textEdit.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.right: parent.right
        height:1
        color: "#000000"
        z:-1
    }

    Text {
        id: showText
        anchors.top: textEdit.bottom
        anchors.topMargin:  30
        anchors.left: textEdit.left

        width: 40
        height: 25

        color: "black"
        font.pixelSize: 25
        text: "接收client dbus!"
    }

    Rectangle {
        anchors.top: showText.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.right: parent.right
        height:1
        color: "#000000"
        z:-1
    }

    TextEdit {
        id: keyTextEdit
        anchors.top: showText.bottom
        anchors.topMargin: 40

        anchors.left: parent.left
        anchors.leftMargin: 20

        width: 100
        height: 25

        font.pixelSize: 20
        text: qsTr("key")

        Rectangle {
            anchors.fill: parent
            color: "lightblue"
            z:-1
        }
    }

    TextEdit {
        id: valueTextEdit
        anchors.top: keyTextEdit.top
        anchors.left: keyTextEdit.right
        anchors.leftMargin: 20

        width: 100
        height: 25

        font.pixelSize: 20
        text: qsTr("value")

        Rectangle {
            anchors.fill: parent
            color: "lightblue"
            z:-1
        }
    }

    Text {
        anchors.top: keyTextEdit.top
        anchors.left: valueTextEdit.right
        anchors.leftMargin:  20

        width: 80
        height: 30

        color: "black"
        font.pixelSize: 25
        text: "biu ~!"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                dbusservice.sendTypeDBus(keyTextEdit.text, valueTextEdit.text)
            }
        }

        Rectangle {
            anchors.fill: parent
            color: "#909090"
            z:-1
            radius: 5
        }
    }

    Text {
        id: defultText
        anchors.top: keyTextEdit.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        color: "black"
        font.pixelSize: 20
        text: qsTr("想使用自己的数据结构任性一下怎么办？")
    }

    Text {
        anchors.horizontalCenter:  parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40

        font.pixelSize: 20
        color: "red"
        text: qsTr("Hello DBus Service !")
    }
}
