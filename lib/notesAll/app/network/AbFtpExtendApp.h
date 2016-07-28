#ifndef ABFTPEXTENDAPP_H
#define ABFTPEXTENDAPP_H

#include <QObject>
#include <QtNetwork>

class AbFtpExtendApp : public QObject
{
    Q_OBJECT
public:
    explicit AbFtpExtendApp(QObject *parent = 0);

    bool getDirectory(const QUrl &url);

signals:
    void done();

private slots:
    void ftpDone(bool error);
    void ftpListInfo(const QUrlInfo &urlInfo);

private:
    void processNextDirectory();

    QFtp ftp;
    QList<QFile *> openedFiles;
    QString currentDir;
    QString currentLocalDir;
    QStringList pendingDirs;
};

//QStringList args = QCoreApplication::arguments();

//if (args.count() != 2) {
//    std::cerr << "Usage: spider url" << std::endl
//              << "Example:" << std::endl
//              << "    spider ftp://ftp.trolltech.com/freebies/"
//              << "leafnode" << std::endl;
//    return 1;
//}

//Spider spider;
//if (!spider.getDirectory(QUrl(args[1])))
//    return 1;

//QObject::connect(&spider, SIGNAL(done()), &app, SLOT(quit()));
#endif // ABFTPEXTENDAPP_H
