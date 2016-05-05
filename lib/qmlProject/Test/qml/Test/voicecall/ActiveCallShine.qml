import QtQuick 2.0

Rectangle{
    id: root
    width: 300
    height: 300

    color: 'black'

    property int index: 1

    Timer {
        id: diaplay
        repeat: true
        interval: 200
        running: true
        onTriggered: {
            if(index == 1)
            {
                one.visible = true;
                two.visible = false;
                three.visible = false;
                index++;
            }
            else if (index == 2)
            {
                one.visible = true;
                two.visible = true;
                three.visible = false;
                index++;
            }
            else
            {
                one.visible = true;
                two.visible = true;
                three.visible = true;
                if(index == 3)
                {
                    index = 1
                }
            }
        }
    }

    property variant items: [ 'xingkong','dao']

    Rectangle{
        id: one
        anchors.centerIn: parent
        width: 10
        height: 10
        radius:  45
    }

    Rectangle{
        id: two
        anchors.verticalCenter: one.verticalCenter
        anchors.left: one.right
        anchors.leftMargin: 10
        width: 10
        height: 10
        radius:  45
    }

    Rectangle{
        id: three
        anchors.verticalCenter: two.verticalCenter
        anchors.left: two.right
        anchors.leftMargin: 10
        width: 10
        height: 10
        radius:  45
    }


    Component.onCompleted: {
        for(var i = 0; i< 2; i++)
        {
            console.log(items[i]);
            console.log('%cTest output', 'color:white; background-color:blue');
        }
    }

}
