import QtQuick 1.1

Rectangle {
    width: 600
    height: 462

    property ListModel _model: ListModel{

    }

    ListView{
        id: view
        anchors.top: parent.top
        width: parent.width
        height: 300
        model: _model
        delegate: EPDelegate_1{}
    }

    Component.onCompleted: {
        _model.append({'name':'xingkongdao'});
        _model.append({'name':'zhengsihua'});
        view.model = _model;
        console.log("===========",_model.get(0).name)

        if('xingkongdao' === qsTr('xingkongdao'))
        {
            console.log('xingkongdao')
        }
    }
}
