import QtQuick 1.1

Rectangle {
    width:500
    height:500

    state: "one"
    Rectangle{
        id:test
//        anchors.centerIn: parent
        x: 200
        y: 200
        width: 100
        height: 100
        color: "red"
    }

    states: [
        State{
            name:"zero"
//            PropertyChanges {
//                target: test
//                opacity: 1
//            }
            PropertyChanges {
                target: test
                y: -50
            }
        },

        State {
            name: "one"
//            PropertyChanges {
//                target: test
//                opacity: 1
//            }

            PropertyChanges {
                target: test
                y:200

            }
        }

    ]

    transitions: [
        Transition {
            from: "one"
            to: "zero"
           SequentialAnimation {
               ParallelAnimation {
                   PropertyAnimation{
                       target: test
                       properties: "y";
                       easing.type: Easing.OutBounce;
                       to: -50
                       duration: 1000
                   }
               }
           }
        },

        Transition {
            from: "zero"
            to: "one"
           SequentialAnimation {
               ParallelAnimation {
                   PropertyAnimation{
                       target: test
                       properties: "y";
                       easing.type: Easing.OutBounce;
                       to: 200
                       duration: 1000
                   }
               }
           }
        }
    ]
    MouseArea{
        anchors.fill: parent

        onClicked: {
            if(parent.state == 'one')
            {
                parent.state = 'zero';
            }
            else
            {
                parent.state = 'one'
            }
        }
    }
}
