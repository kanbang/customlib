#include <QApplication>
#include <QtDeclarative>
#include <QVariant>

#include "dbusclient.h"
#include "dbuswatcher.h"

const QString FILEPATH = QDir::homePath() + "/KuaiPan/learn/program/notesAll/app/SYDbusClient/main.qml";

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDeclarativeView view;

    DBusClient dbusclient;
    DBusWatcher dbuswatcher;

    view.engine()->rootContext()->setContextProperty("dbusclient", &dbusclient);
    view.engine()->rootContext()->setContextProperty("dbuswatcher", &dbuswatcher);

    view.setSource(QUrl::fromLocalFile(FILEPATH));

    view.show();

    return app.exec();
}
