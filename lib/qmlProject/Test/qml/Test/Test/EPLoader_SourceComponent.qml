// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 400
    height: 400

    Component {
        id: redSquare
        Rectangle {
            id:testRect
            color: "red";
            width: 100;
            height: 100

            MouseArea {
                anchors.fill: parent
                onClicked:  {
                    testRect.color = "blue"
                }
            }
        }

//        Component.onCompleted: {
//            console.log("dddddddddddddddddddddddddddddddd");
//        }
    }

    Loader { sourceComponent: redSquare }

    Timer {
             interval: 3000; running: true; repeat: false
             onTriggered: {
                loader.sourceComponent = redSquare
                 loader.x = 150
             }

         }

    Loader {
        id:loader
//        sourceComponent: redSquare;
//        x: 150
    }

    ListModel {
        id: fruitModel

        /*ListElement 的数据是由自己定义的，然后通过代理获得数据，
           最后通过ListView来显示的
          */
        ListElement {
            name: "Apple"
            cost: 2.45
            iconOn: "../SmartHome/pics/icons/light_on.png"
        }
        ListElement {
            name : "Orange"
            cost: 3.25
            iconOn: "../SmartHome/pics/icons/light_off.png"
        }
        ListElement {
            name: "Banana"
            cost: 1.95
            xkd: 10000
            iconOn: "../SmartHome/pics/icons/light_off.png"
        }
    }

    ListView {
        model: fruitModel
        delegate: Item {
            Text{
                text: name
                Component.onCompleted: {
                    console.log("dddddddddddddddddddddddddddddddd");
                }
            }

        }
    }
}
