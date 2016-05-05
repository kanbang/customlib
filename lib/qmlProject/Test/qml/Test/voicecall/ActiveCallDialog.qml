import QtQuick 1.1

Rectangle {
    id: root

    property variant items: [ syPortrait]
//    property variant statesTexts: ['dialing','incoming', 'alerting','waiting', 'hold', 'disconnected','acitve', 'harassment', 'hideFlags'];
    property variant statesTexts:['dialing', 'contact', 'harassment', 'active']
    property double divscale : 0.6
    width: 720*divscale
    height: 1280*divscale
    color: "lightgray"

    Image {
        anchors.fill: parent

        source: "../helloworld/App/PanelBackGround(11).png"
        sourceSize:Qt.size(root.width, root.height)
    }

    ActiveCallPortrait{
        id: syPortrait
    }

    ActiveCallToolMenu{
        id: syToolmenu
        width: root.width
        anchors.top: syPortrait.bottom
        anchors.left: root.left

        visible: false
    }

    NumPad {
        id: keyboard

        width: root.width
        anchors.top: syPortrait.bottom
        anchors.topMargin: 100

        anchors.left: root.left
        anchors.leftMargin: 70
        visible: false
    }

    ActiveCallIncomePanel {
        id: syIncomepanel

        width: root.width
        height: 250*divscale
        anchors.bottom: root.bottom
        anchors.bottomMargin: 100*divscale
        anchors.left:  root.left
    }

    Item {
        id: hungup
        width: root.width;
        height: 100*divscale
        anchors.bottom:  root.bottom
        anchors.bottomMargin: 100*divscale
        visible: false

        Rectangle {
            id: hungupImg;
            width: 280*divscale;
            height: 100*divscale
            color: "red";
            smooth:  true
            radius: 35
            anchors.horizontalCenter:  hungup.horizontalCenter
            MouseArea {
                anchors.fill:  parent

                onClicked: {
                    syIncomepanel.visible = true;
                    syToolmenu.visible = false;
                    hungup.visible = false;
                }
            }
        }
        Image {
            id: igKeyboard
            anchors.left: hungupImg.right
            anchors.leftMargin:  60*divscale
            anchors.verticalCenter: hungupImg.verticalCenter
            smooth:  true
            source: "./image/jianpan1.png"
            sourceSize: Qt.size(70*divscale, 70*divscale)
            property bool  show: false

            MouseArea{
                anchors.fill:  parent

                onClicked: {
                    igKeyboard.show = !igKeyboard.show;
                    if(igKeyboard.show)
                    {
                        keyboard.visible = true;
                        syToolmenu.visible = false;
                    }
                    else
                    {
                        keyboard.visible = false;
                        syToolmenu.visible = true;
                    }
                }
            }
        }
    }

    Rectangle {
        id: syKeyboard

        width: 70*divscale
        height: 70*divscale
        anchors.left: hungup.right
        anchors.leftMargin:  80*divscale
        anchors.verticalCenter: hungup.verticalCenter
        smooth:  true
        visible: false
        color: "white"
    }

    MouseArea {
        anchors.fill: parent

        enabled: false
        onPressed: {
            console.log("==========================pressed")
        }

        onReleased: {
            console.log("==========================release")
        }
    }

    Timer {
        repeat:  true
        interval:  1000
        running:  true

        property int index: 0
        onTriggered: {

            for(var i = 0; i<items.length; i++)
            {
                items [i].layoutForState(statesTexts[index]);
            }

            index++;
            if(index >=statesTexts.length)
            {
                index = 0;
            }
        }
    }
}
