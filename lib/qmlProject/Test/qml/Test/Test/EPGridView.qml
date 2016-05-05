import QtQuick 1.1

GridView {
    width: 700
    height: 600

    cellHeight: 300
    cellWidth: 200
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
        ListElement {
            name: "Banana"
            cost: 1.95
            xkd: 10000
            iconOn: "../SmartHome/pics/icons/light_off.png"
        }
        ListElement {
            name: "Banana"
            cost: 1.95
            xkd: 10000
            iconOn: "../SmartHome/pics/icons/light_off.png"
        }
        ListElement {
            name: "Banana"
            cost: 1.95
            xkd: 10000
            iconOn: "../SmartHome/pics/icons/light_off.png"
        }
    }

    model: fruitModel
    Component {
        id: fruitDelegate
        Column {
            spacing : 10
            Image {
                source: model.iconOn
            }
            Image {
                source: model.iconOn
            }

            Text {
                text: model.cost + model.name
            }
           }
    }

    delegate: fruitDelegate
}
