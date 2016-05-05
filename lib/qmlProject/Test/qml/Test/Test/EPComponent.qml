// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

/****
  每一个写好的qml文件都是一个Component，都可以用来做 view 的delegate
  delegate 的作用是用来显示view 里面的每一个index的表现形式

  */
Item {
    id: root
    width: 100
    height: 100

    Rectangle{
        anchors.fill: parent

        color: "red"

        Text{
            z:1
            anchors.centerIn: parent
            text: model.name
        }
        Image {
            z:0
            anchors.centerIn: parent
            source: model.iconOn
        }
    }


//    Row {
//        spacing: 20
////        Rectangle{
//            Text{
////                width: parent.width
////                height:parent.height
////                anchors.centerIn: parent
//                text: "model.name"
//            }
//            Text{
////                width: parent.width
////                height:parent.height
////                anchors.centerIn: parent
//                text: "model.name"
//            }
////        }

////        Image {
//////            width: parent.width
//////            height:parent.height
//////            anchors.centerIn: parent
////            source: "model.iconOn"
////        }
//    }
}

//Component {

//    Rectangle {

//        id:wrapper

//        width: 30;

//        height: 30;

//        BorderImage {

//            id:bg_element

////                    source: wrapper.isCurrent

//            anchors.fill:parent;

//            border.left: 5; border.top: 5

//            border.right: 5; border.bottom: 5

//        }

//        Text {

//            anchors.left: parent.left;

//            anchors.verticalCenter: parent.verticalCenter;

////            anchors.leftMargin: parent.width * 0.6;

//            verticalAlignment: Text.AlignVCenter;

//            font.family: "SimSun";

//            text: model.name;

//        }

//        MouseArea {

//            anchors.fill: parent;

//            hoverEnabled: true;

//            onEntered: {

//                console.log("enter");

//                bg_element.source = "../SmartHome/pics/icons/light_off.png";

//            }

//            onExited: {

//                console.log("exit");

//                bg_element.source = "../SmartHome/pics/icons/light_on.png"

//            }

//            onClicked: {

//                console.log("index",index);

//                wrapper.ListView.view.currentIndex = index;

//                console.log("current index",wrapper.ListView.view.currentIndex);

//                console.log("is current item",wrapper.ListView.isCurrentItem);

//                console.log("model:",wrapper.ListView.view.model);

//                console.log("clicked");

//                bg_element.source = "../SmartHome/pics/icons/light_off.png";

//            }

//        }

//    }

//}
/**

Component {
        id:featureButtonsDelegate
        Rectangle
        {
            property bool pressed: false;
            id:wrapper;
            width: wrapper.ListView.view.width;
            height: Math.max(wrapper.ListView.view.height/wrapper.ListView.view.model.count,40);
            color: "lightblue";
            border.width: 0;
            Text {
                id: text
                anchors.centerIn: parent;
                text: model.name;
            }

            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    root.sigItemClicked(text.text,pressed);
                    for(var i=0;i<wrapper.ListView.count;i ++) {
                        if(i!=index) {
                        }
                    }
                }
            }

            states: [
                State {
                    name: "pressed"; when: wrapper===true;
                    PropertyChanges {
                        target: wrapper;
                        color: "deepskyblue";
                    }
                }
            ]
            transitions: [
                Transition {
                    ColorAnimation { target: wrapper; duration: 200; }
                }
            ]
        }
    }
*/
