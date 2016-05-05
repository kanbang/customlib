import QtQuick 1.1

Column{

    spacing: 100*divscale
    anchors.leftMargin: (720-3*(106))*divscale/4
    anchors.topMargin: 300*divscale
    property double bgWidth: 106*divscale
    property double bgHeight: 124*divscale
    property double iWidth: 40*divscale
    property double iHeight: 40*divscale

     Row {
        spacing: (720-3*(106))*divscale/4

        Image {
            source: "./image/toolbg.png"

            sourceSize: Qt.size(bgWidth, bgHeight)
            Image {
                anchors.centerIn: parent
                source: "./image/mute.png"

                sourceSize: Qt.size(iWidth, iHeight)
            }

            Text {
                anchors.top:  parent.bottom
                anchors.topMargin: 10*divscale
                anchors.horizontalCenter: parent.horizontalCenter
                text: "mute"
            }

            MouseArea{
                anchors.fill: parent

                onPressed:  {
                    parent.opacity = 0.2
                }

                onReleased:   {
                    parent.opacity = 1.0
                }
            }
        }

        Image {
            source: "./image/toolbg.png"
            sourceSize: Qt.size(bgWidth, bgHeight)
            property bool bactive: false

            Image {
                id: mianti
                anchors.centerIn: parent
                source: parent.bactive ? "./image/mianti_active.png" : "./image/mianti.png"
                sourceSize: Qt.size(iWidth, iHeight)
            }

            Text {
                anchors.top:  parent.bottom
                anchors.topMargin: 10*divscale
                anchors.horizontalCenter: parent.horizontalCenter
                text: "speaker"
            }

            MouseArea{
                anchors.fill: parent

                onPressed:  {
                    parent.opacity = 0.2
                }

                onReleased:   {
                    parent.opacity = 1.0
                    parent.bactive = !parent.bactive;
                }
            }
        }

        Image {
            source: "./image/toolbg.png"
            sourceSize: Qt.size(bgWidth, bgHeight)
            Image {
                anchors.centerIn: parent
                source: "./image/note.png"
                sourceSize: Qt.size(iWidth, iHeight)
            }

            Text {
                anchors.top:  parent.bottom
                anchors.topMargin: 10*divscale
                anchors.horizontalCenter: parent.horizontalCenter
                text: "note"
            }

            MouseArea{
                anchors.fill: parent

                onPressed:  {
                    parent.opacity = 0.2
                }

                onReleased:   {
                    parent.opacity = 1.0
                }
            }
        }
    }

    Row {
        spacing: (720-3*(106))*divscale/4

        Image {
            source: "./image/toolbg.png"

            sourceSize: Qt.size(bgWidth, bgHeight)
            Image {
                anchors.centerIn: parent
                source: "./image/hebing.png"
                sourceSize: Qt.size(iWidth, iHeight)
            }

            Text {
                anchors.top:  parent.bottom
                anchors.topMargin: 10*divscale
                anchors.horizontalCenter: parent.horizontalCenter
                text: "merge"
            }

            MouseArea{
                anchors.fill: parent

                onPressed:  {
                    parent.opacity = 0.2
                }

                onReleased:   {
                    parent.opacity = 1.0
                }
            }
        }

        Image {
            source: "./image/toolbg.png"
            sourceSize: Qt.size(bgWidth, bgHeight)

            Image {
                anchors.centerIn: parent
                source: "./image/qiehuan.png"
                sourceSize: Qt.size(iWidth, iHeight)
            }

            Text {
                anchors.top:  parent.bottom
                anchors.topMargin: 10*divscale
                anchors.horizontalCenter: parent.horizontalCenter
                text: "switch"
            }

            MouseArea{
                anchors.fill: parent

                onPressed:  {
                    parent.opacity = 0.2
                }

                onReleased:   {
                    parent.opacity = 1.0
                }
            }
        }

        Image {
            source: "./image/toolbg.png"
            visible:  false
            sourceSize: Qt.size(bgWidth, bgHeight)
            Image {
                anchors.centerIn: parent
                source: "./image/mute.png"
                sourceSize: Qt.size(iWidth, iHeight)
            }

            Text {
                anchors.top:  parent.bottom
                anchors.topMargin: 10*divscale
                anchors.horizontalCenter: parent.horizontalCenter
                text: "hold"
            }

            MouseArea{
                anchors.fill: parent

                onPressed:  {
                    parent.opacity = 0.2
                }

                onReleased:   {
                    parent.opacity = 1.0
                }
            }
        }

        Image {
            source: "./image/toolbg.png"
            visible:  false
            sourceSize: Qt.size(bgWidth, bgHeight)
            Image {
                anchors.centerIn: parent
                source: "./image/add.png"
                sourceSize: Qt.size(iWidth, iHeight)
            }
            Text {
                anchors.top:  parent.bottom
                anchors.topMargin: 10*divscale
                anchors.horizontalCenter: parent.horizontalCenter
                text: "add"
            }

            MouseArea{
                anchors.fill: parent

                onPressed:  {
                    parent.opacity = 0.2
                }

                onReleased:   {
                    parent.opacity = 1.0
                }
            }
        }
        Image {
            source: "./image/toolbg.png"
            sourceSize: Qt.size(bgWidth, bgHeight)
            Image {
                anchors.centerIn: parent
                source: "./image/contact.png"
                sourceSize: Qt.size(iWidth, iHeight)
            }

            Text {
                anchors.top:  parent.bottom
                anchors.topMargin: 10*divscale
                anchors.horizontalCenter: parent.horizontalCenter
                text: "contact"
            }

            MouseArea{
                anchors.fill: parent

                onPressed:  {
                    parent.opacity = 0.2
                }

                onReleased:   {
                    parent.opacity = 1.0
                }
            }
        }
    }
}
