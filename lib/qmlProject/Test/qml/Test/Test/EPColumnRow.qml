// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Column {
    id: root
    width: 200
    height: 400

    Row {
        width: root.width

        Image {
            source: "../SmartHome/pics/icons/light_on.png"
        }

        Image {
            source: "../SmartHome/pics/icons/light_on.png"
        }

        Image {
            source: "../SmartHome/pics/icons/light_on.png"
        }
    }

    Row {
        anchors.horizontalCenter: root.horizontalCenter

        width: childrenRect.width

        Image {
            source: "../SmartHome/pics/icons/light_on.png"
        }


        Image {
            source: "../SmartHome/pics/icons/light_on.png"
        }
    }
}
