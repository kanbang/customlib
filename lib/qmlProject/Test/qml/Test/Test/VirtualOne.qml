import QtQuick 1.1

Rectangle {
    id: oneItem
    x: 50
    y: 50
    width: 100
    height:100
    color:  "blue"
    property variant items: [oneText];
    Rectangle {
        width: 100
        height: 20

        anchors.centerIn: {parent}

        color:"white"
        Text {
            id: oneText
            width: 100
            height:20
            anchors.fill: {parent}
            horizontalAlignment: Text.AlignHCenter
            color: "black"
            visible: false

            function testVirtual(_states)
            {
                oneText.text = _states;
            }
        }
    }


    MouseArea {
        anchors.fill: parent

        onClicked: {
            console.log("=======================",root.index,"===index===",index);
            root.index = 2;
            console.log("=======================",root.index,"===index===",index);
        }
    }

    property int  type: 0;

    function testVirtual(_states)
    {
        if(oneItem.color =="#0000ff")
        {
            oneItem.color = "red";
        }
        else
        {
            oneItem.color = "blue"
        }
        for(var i = 0; i<oneItem.items.length; i++)
        {
            items [i].testVirtual(_states);
        }
    }


}
