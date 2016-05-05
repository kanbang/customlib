import QtQuick 1.1

//Column {
//    property double bgWidth: 112*divscale
//    property double bgHeight: 134*divscale

//    anchors.leftMargin: (720-3*(bgWidth))*divscale/4
//    Row {
//        Image{
//            source: "./image/keyboardbg.png"
//            sourceSize: Qt.size(bgWidth, bgHeight);
//            anchors.centerIn: parent

//            Item {
//                width: 50
//                height: 50
//                anchors.centerIn: parent
//                Text{
//                    id: keyNumber
//                    text: "1"
//                    anchors.centerIn: parent
//                    font.pixelSize: 30
//                }

//                Text {
//                    id: keyChar
//                    anchors.top: keyNumber.bottom
//                    anchors.topMargin: 0
//                    anchors.horizontalCenter: keyNumber.horizontalCenter
//                }
//            }
//        }
//        Image{
//            source: "./image/keyboardbg.png"
//            sourceSize: Qt.size(bgWidth, bgHeight);
//            anchors.centerIn: parent

//            Item {
//                width: 50
//                height: 50
//                anchors.centerIn: parent
//                Text{
//                    id: keyNumber
//                    text: "1"
//                    anchors.centerIn: parent
//                    font.pixelSize: 30
//                }

//                Text {
//                    id: keyChar
//                    anchors.top: keyNumber.bottom
//                    anchors.topMargin: 0
//                    anchors.horizontalCenter: keyNumber.horizontalCenter
//                }
//            }
//        }
//        Image{
//            source: "./image/keyboardbg.png"
//            sourceSize: Qt.size(bgWidth, bgHeight);
//            anchors.centerIn: parent

//            Item {
//                width: 50
//                height: 50
//                anchors.centerIn: parent
//                Text{
//                    id: keyNumber
//                    text: "1"
//                    anchors.centerIn: parent
//                    font.pixelSize: 30
//                }

//                Text {
//                    id: keyChar
//                    anchors.top: keyNumber.bottom
//                    anchors.topMargin: 0
//                    anchors.horizontalCenter: keyNumber.horizontalCenter
//                }
//            }
//        }

//    }

//    Row{

//    }

//    Row{

//    }

//    Row{

//    }
//}

GridView {

    width: parent.width
    height: 500*divscale
    cellWidth: width/3-10
    cellHeight: height/3-10

    model: ListModel {
        ListElement {key:'1';sub:''}
        ListElement {key:'2';sub:'abc'}
        ListElement {key:'3';sub:'def'}
        ListElement {key:'4';sub:'ghi'}
        ListElement {key:'5';sub:'jkl'}
        ListElement {key:'6';sub:'mno'}
        ListElement {key:'7';sub:'pqrs'}
        ListElement {key:'8';sub:'tuv'}
        ListElement {key:'9';sub:'wxyz'}
        ListElement {key:'*';sub:'+';alt:'+'}
        ListElement {key:'0';sub: ""}
        ListElement {key:'#';sub:"";alt:'p'}
    }

    delegate: NumPadButton{}
}
