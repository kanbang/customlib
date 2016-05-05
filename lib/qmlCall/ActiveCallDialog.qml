import QtQuick 2.2

Rectangle {
    id: root

    property variant items: [ syPortrait]
//    property variant statesTexts: ['dialing','incoming', 'alerting','waiting', 'hold', 'disconnected','acitve', 'harassment', 'hideFlags'];
    property variant statesTexts:['dialing', 'contact', 'harassment']
    property double divscale : 0.6
    width: 720*divscale
    height: 1280*divscale
    color: "red"

    ActiveCallPortrait{
        id: syPortrait
    }

    ActiveCallToolMenu{
        id: toolmenu
        anchors.top: syPortrait.bottom
        anchors.left: root.left
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
