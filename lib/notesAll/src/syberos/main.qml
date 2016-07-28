// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 300
    height: 300

 //   color: backgroundColor

    Rectangle {
	objectName: "rect"
	x: 50
	y: 50
	width: 130
	height: 150
	color: "lightblue"
	Text {
		objectName: "Hello"
		anchors.centerIn: parent
		text: "Children Text"
		color: "blue"
	}
    }
    Text{

	objectName:"text"
        anchors.centerIn: parent
        text: "Hello World !"
	color: "green"
    }

    MouseArea{
        id: _mouse

        onClicked: {
            var xkd = "xingkongdao";
            console.log(xkd.indexOf(1,2));
        }
    }
}
