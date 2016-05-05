import QtQuick 1.1
Rectangle {
    id: root
    property Item item: null
    property variant items: [one, two];
    property variant statesText: ['dialing','incoming', 'alerting','waiting', 'hold', 'disconnected','acitve'];
    width: 400
    height:400
    color: "lightGray"
    VirtualOne {
            id: one
    }

    VirtualTwo {
        id:two

        visible: true
    }

    Timer {
        repeat:  true
        interval:  1000
        running:  false

        property int index: 0
        onTriggered: {

            for(var i = 0; i<items.length; i++)
            {
                items [i].testVirtual(statesText[index]);
            }

            index++;
            if(index >6)
            {
                index = 0;
            }
        }
    }
}
