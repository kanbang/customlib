#include <QApplication>
#include <QtDeclarative>

#include "dbusservice.h"

const QString FILEPATH = QDir::homePath() + "/KuaiPan/learn/program/notesAll/app/SYDbusService/main.qml";

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDeclarativeView view;

    DBusService dbusservice;

    view.engine()->rootContext()->setContextProperty("dbusservice", &dbusservice);

    view.setSource(QUrl(FILEPATH));

    view.show();

    return app.exec();
}
