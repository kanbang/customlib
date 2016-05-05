// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import EPQml 1.0

Rectangle {
    width: 300
    height: 162

    MouseArea{
        anchors.fill: parent

        onClicked: {
            qml.show();
//            qml.widget.show();
        }        
    }

    EPQml {
        id: qml

        onTestSignal: {
            if(message == "xingkd")
            {
                console.log("emit", para1);
                console.log(message);
                widget.setWindowTitle("zhengsihua");
                widget.show();
            }

        }
    }

//    _qml.onTestSignal: {
//        console.log("xingkongdao");
//    }

//    Component.onCompleted: {

//    }


    Connections{
        target: _qml

        onTestSignal:{
//            if(m_value == 10)
            {
                console.log("m_value");
            }

            console.log("xingkongdao");
            console.log(qml.getValue());            
        }
    }
}
