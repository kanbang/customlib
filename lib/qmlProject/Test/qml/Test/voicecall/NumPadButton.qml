import QtQuick 1.1

Item {
    id: keyDelegate

    property double bgWidth: 112*divscale
    property double bgHeight: 134*divscale

    Image{
        id: bgkey
        source: "./image/keyboardbg.png"
        sourceSize: Qt.size(bgWidth, bgHeight);
        anchors.centerIn: parent

        Item {
            width: 50
            height: 50
            anchors.centerIn: parent
            Text{
                id: keyNumber
                text: model.key
                anchors.centerIn: parent
                font.pixelSize: 30
            }
            Text {
                id: keyChar
                anchors.top: keyNumber.bottom
                anchors.topMargin:1
                anchors.horizontalCenter: keyNumber.horizontalCenter
                text: model.sub
            }
        }
        MouseArea{
            anchors.fill: parent

            onPressed: {
                parent.opacity = 0.2
            }

            onReleased: {
                parent.opacity = 1.0
            }
        }
    }
}
