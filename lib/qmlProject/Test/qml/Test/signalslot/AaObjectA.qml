import QtQuick 1.1

Item {
    id: _a
    width:200
    height:200

    function showB(){
        var component = Qt.createComponent("testSignalB");
        if(component.status == Component.Ready){
            var bQml = component.createObject(_a);
            bQml.xClicked.connect(doSomething);
        }
    }

    function doSomething(msg){
        console.log(msg + "do something");
    }

    MouseArea {
        anchors.fill:  parent
        onClicked: showB()
    }
}
