// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle{
    width: 350
    height: 400    // rect.height

    color: "lightblue"

    Rectangle{
        id: rect
        width: parent.width/2

        anchors.right: parent.right
        height: parent.height

        color: "blue"

        Image {
            id: justiina
            smooth: true
            width: parent.width

            fillMode:Image.PreserveAspectFit
            source: "App/PanelBackGround(0).png"
            opacity: 0.8
        }
    }

    Text{

    }
}
