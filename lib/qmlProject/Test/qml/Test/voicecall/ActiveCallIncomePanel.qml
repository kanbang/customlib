import QtQuick 1.1

Column {
    id: incomepanel
    spacing:  70*divscale

    Row {

        Item {
            width: (root.width - 280*divscale*2)/3
            height: 100*divscale
        }

        Rectangle {
            id: reject
            color: "red";
            width: 280*divscale;
            height: 100*divscale
            smooth:  true
            radius: 35

            MouseArea {
                anchors.fill:  parent

                onClicked: {
                    root.visible = false
                }
            }
        }

        Item {
            width: (root.width - 280*divscale*2)/3
            height: 100*divscale
        }

        Rectangle {
            id: accept
            color: "green";
            width: 280*divscale;
            height: 100*divscale
            smooth: true
            radius: 35

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("=======================")
                    incomepanel.visible = false
                    syToolmenu.visible = true
                    hungup.visible = true
                }
            }
        }

        Item {
            width: (root.width - 280*divscale*2)/3
            height: 100*divscale
        }
    }

    Row {
        Item {
            width: (root.width - 100*divscale*2 - 50)/3
            height: 100*divscale
        }

        Rectangle {
            color: "blue";
            width: 100*divscale;
            height: 100*divscale
            smooth: true
            radius: 45
        }

        Item {
            width: (root.width - 100*divscale*2 + 100)/3
            height: 100*divscale
        }

        Rectangle {
            color: "blue";
            width: 100*divscale;
            height: 100*divscale
            smooth: true
            radius: 45
        }
    }
}
