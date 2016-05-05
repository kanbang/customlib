// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
     id: _signal
     width: 200; height: 200
     state: "Max"
     color: "lightBlue"

     states: [
         State {
             name: "NORMAL"
             PropertyChanges { target: _signal; color: "green"}
//             PropertyChanges { target: flag; state: "FLAG_DOWN"}
         },
         State {
             name: "CRITICAL"
             PropertyChanges { target: _signal; color: "red"}
//             PropertyChanges { target: flag; state: "FLAG_UP"}
         },

         State {
             name: "Max"

             PropertyChanges { target: _signal; width: 400 }

             PropertyChanges { target: _signal; height: 400 }
         },

         State {
             name: "Min"
             PropertyChanges { target: _signal; width: 100 }
             PropertyChanges { target: _signal; height: 100 }
         }

     ]

     transitions: [
         Transition {
             from: "Max"
             to: "Min"

             PropertyAnimation { target: _signal
                 properties: "width";
                 duration: 1000
             }

             PropertyAnimation { target: _signal
                 properties: "height";

                 duration: 1000
             }
         },

         Transition {
             from: "Min"
             to: "Max"

             PropertyAnimation { target: _signal
                 properties: "height";
                 duration: 1000
             }

             PropertyAnimation { target: _signal
                 properties: "width";
                 duration: 1000

             }
         }
     ]
    MouseArea{
        anchors.fill: parent

        onClicked: {
            console.log("boundingRect ", _signal.boundingRect);
            if(_signal.state == "Max")
            {
                _signal.state = "Min";
            }
            else
            {
//                _signal.state = "NORMAL";
                _signal.state = "Max";
            }
        }
    }
 }
