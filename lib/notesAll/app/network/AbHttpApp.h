#ifndef ABHTTPAPP_H
#define ABHTTPAPP_H

#include <QObject>
#include <QtNetwork>

class AbHttpApp : public QObject
{
    Q_OBJECT
public:
    explicit AbHttpApp(QObject *parent = 0);

    bool getFile(const QUrl &url);

signals:
    void done();

private slots:
    void httpDone(bool error);

private:
    QHttp http;
    QFile file;
};

//QStringList args = QCoreApplication::arguments();

//if (args.count() != 2) {
//    std::cerr << "Usage: httpget url" << std::endl
//              << "Example:" << std::endl
//              << "    httpget http://doc.trolltech.com/index.html"
//              << std::endl;
//    return 1;
//}

//HttpGet getter;
//if (!getter.getFile(QUrl(args[1])))
//    return 1;

//QObject::connect(&getter, SIGNAL(done()), &app, SLOT(quit()));
#endif // ABHTTPAPP_H
