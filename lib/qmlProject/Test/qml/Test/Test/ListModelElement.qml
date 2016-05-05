import QtQuick 1.1
import "../SmartHome"

Rectangle {
    id: root
    width: 480
    height: 768
    property alias fruit :fruitModel

    color : "lightblue"
    property ListModel m_model: ListModel{

        ListElement {
            name: "Fuck"
            cost: 2.45
            iconOn: "../SmartHome/pics/icons/light_on.png"
        }
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
    Component {
        id: fruitDelegate
        Column {
            spacing : 10
            Text {
                text: model.name
            }
            Text {
                anchors.centerIn: parent
                text: model.cost + model.name
            }
            Image {
                anchors.centerIn: parent
                source: model.iconOn
            }
            Image {
                anchors.centerIn: parent
                source: model.iconOn
            }

            Item{
                width: 300
                height: 20;

                Rectangle{
                    anchors.fill: parent

                    color:"red"
                }
            }
        }
    }

    ListView {
        id: listView
        anchors.fill: parent
        model: fruitModel
        delegate:Component {
            Column {
                spacing : 10
                Text {
    //                anchors.centerIn: parent
                    text: name
                }
                Text {
                    text: cost + name
                }
                Image {
                    source: iconOn
                }
            }
        }
            //fruitDelegate //EPComponent{} //
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            console.log("count = ", root.m_model.count);
            root.m_model = fruitModel;
            console.log("fruitModel = ", root.m_model.count);
            console.log("item ", listView.currentItem.data.objectName);
            listView.model.get(0).name = "xingkongdao";
//            listView.model.remove(0);

        }
    }
}
