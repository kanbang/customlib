// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 100
    height: 62

    property ListModel oModel : ListModel{

    }

    MouseArea{
        id: _mouse;
        anchors.fill: parent

        onClicked: {
            oModel.append({"name": "xingkongdao", "age": 26});

            console.log("log", oModel.get(0).name);
        }

    }
}
