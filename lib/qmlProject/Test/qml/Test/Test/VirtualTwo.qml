import QtQuick 1.1

Rectangle {
    id: twoItem
    x: 200
    y: 200
    width: 100
    height:100
    color: "red"
    property int  type: 1;

    function testVirtual(_states)
    {
        if(twoItem.color =="#ff0000")
        {
            twoItem.color = "blue";
        }
        else
        {
            twoItem.color = "red";
        }
    }
}
