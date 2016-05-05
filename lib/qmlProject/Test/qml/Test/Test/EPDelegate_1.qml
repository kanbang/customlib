import QtQuick 1.1

Item {
    width: 100
    height: 50
//    anchors.horizontalCenter: parent.horizontalCenter
    anchors.left: parent.horizontalCenter
    Text{
        anchors.centerIn: parent
        text: model.name
    }
    Rectangle{
        anchors.fill: parent
        color: "red"
        opacity: 0.2
    }
    Component.onCompleted: {
        console.log("=================",index);
    }
}
