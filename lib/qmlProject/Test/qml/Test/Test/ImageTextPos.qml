// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item{
    id:item
    width: mainID.width
    height:mainID.height


    Image{
        anchors.centerIn:  parent
        id:sliptrect
        width: 230
        height: 180
        asynchronous: true
        //fillMode: Image.PreserveAspectFit
        smooth: true
        source: "../helloworld/App/Ades.png"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                //console.log("LOOOOOOOOOOOOOOG  CC UI Delegate small2 mouse area ", model.PhoneNumber  )
        //                    main.splitSingleInConf( model.PhoneNumber )
            }
        }
    }
    Text{
//        width: sliptrect.width
//            anchors.centerIn: parent
        anchors.verticalCenter: sliptrect.verticalCenter
        anchors.horizontalCenter : sliptrect.horizontalCenter

        anchors.top: sliptrect.bottom

        text: "Hello World"
        color:"red"
        font.pixelSize: 24
        style: Text.Raised;
        styleColor: "black"
    }
}
