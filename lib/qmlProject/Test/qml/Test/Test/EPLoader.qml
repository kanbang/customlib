// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 400
    height: 562

    property bool isLoader : true
    Loader {
        id: loader

        source: "/home/xkd/KuaiPan/learn/program/qmlProject/Test/qml/Test/Test/EPColumn (澶嶄欢).qml"
        visible:  false
    }

    MouseArea{
        id: mouseArea
        anchors.fill:  parent

        onClicked: {
            if(isLoader)
            {
                loader.visible = true
                isLoader = false;
            }
            else
            {
//                loader.source = "";
                loader.visible = false;
                isLoader = true;
            }
        }
    }

    Item {
        width: 200; height: 200

        Loader {
            // position the Loader in the center of the parent
            anchors.centerIn: parent
            sourceComponent: rect
        }

        Component {
            id: rect
            Rectangle {
                width: 50
                height: 50
                color: "red"
            }
        }
    }
}
