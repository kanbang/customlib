import QtQuick 2.0
import com.syberos.basewidgets 1.0

CPageStackWindow {

    initialPage:CPage{
        Text {
            text: qsTr("Hello SyberOS")
            anchors.centerIn: parent

            Component.onCompleted: {
                console.log("=============xingkongdao=============")
            }
        }

//        CTitleBar
//        {
//            id: titleBar
//            anchors.top: parent.top
//            leftItemEnabled: true;
//            rightItemEnabled: false;
//            leftItemText: "Cancel"
//            leftItemIcon: ""
//            titleText: "xingkongdao"

//        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                Qt.quit();
            }
        }
    }
}
