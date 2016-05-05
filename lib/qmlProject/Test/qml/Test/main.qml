import QtQuick 1.1
import "helloworld"
import "Test"
import "signalslot"
import "voicecall"


ListModelElement {

}

/**
Rectangle{
    id: root
    width: 400
    height: 400
    color: "lightgray"

    Rectangle{
        id: one
        anchors.centerIn: parent
        width: 150
        height: 150
        radius: 90
        smooth: true
        color: "lightgray"

        Text{
            id: txt
            width: 100
            anchors.centerIn: parent
            elide: Text.ElideLeft
            verticalAlignment: Text.AlignTop
            text: "dddddddddddddddddddddd33333333333"
        }
    }

    Rectangle{
        id: two
        property bool  bchange: false
        anchors.bottom: one.top
        color: bchange ? "transparent" : "red"
        border.width: bchange ? 2 : 0
        border.color: "white"
        width: 100
        height: 50
        radius: 45
        smooth: true
    }

    Image{
        source:"./helloworld/App/PanelBackGround(0).png"
//        sourceSize: Qt.size(220,250);
        anchors.centerIn: parent
    }


    Image {
        id: img

        source: "./voicecall/image/maskimg.png"
        sourceSize: Qt.size(120,150);
        anchors.centerIn: parent
//        opacity:
    }



    MouseArea{
        anchors.fill: parent

        onClicked: {
            two.bchange = !two.bchange;
            console.log("z===========",root.z,"=====",one.z,'======',txt.text.length);
            txt.text = "";
            console.log("z===========",root.z,"=====",one.z,'======',txt.text.length);
        }
    }
}
*/
