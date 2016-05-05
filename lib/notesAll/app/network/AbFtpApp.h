#ifndef ABFTPAPP_H
#define ABFTPAPP_H

#include <QObject>
#include <QtNetwork>

class AbFtpApp : public QObject
{
    Q_OBJECT
public:
    explicit AbFtpApp(QObject *parent = 0);

    bool getFile(const QUrl &url);

signals:
    void done();

private slots:
    void ftpDone(bool error);
    void restData();

private:
    QFtp ftp;
    QFile file;
    
};

// 用QCoreApplication是为了防止在编译时连接QtGui程序库。
// QCoreApplication app(argc,argv);
//QStringList args = QCoreApplication::arguments();
//if (args.count() != 2) {
//    std::cerr << "Usage: ftpget url" << std::endl
//              << "Example:" << std::endl
//              << "    ftpget ftp://ftp.trolltech.com/mirrors"
//              << std::endl;
//    return 1;
//}

//FtpGet getter;
//if (!getter.getFile(QUrl(args[1])))
//    return 1;
//    EPFifteenFtpGet getter;
//    if (!getter.getFile(QUrl("ftp://192.100.100.8/pub/epoffice/alpha/rhel4u5/epoffice_alpha-installer_rhel4u5-201301041234.bin")))
//        return 1;

//    QObject::connect(&getter, SIGNAL(done()), &app, SLOT(quit()));
//QObject::connect(&getter, SIGNAL(done()), &app, SLOT(quit()));

#endif // ABFTPAPP_H
