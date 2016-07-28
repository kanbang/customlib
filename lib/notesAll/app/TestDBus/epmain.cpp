#include <QListView>
#include <QApplication>
#include <QDebug>
#include <EPDBus.h>
#include <EPQml.h>
#include <EPSqlite.h>
#include <EPDbusService.h>
#include <EPSyberosAlgo.h>
#include <SyMatchNumber.h>
#include <EPModel.h>
#include <EPMateObject.h>
#include <QDateTime>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    EPService::execClient();

//    EPSyberosAlgo::matchPhoneNumber("4008880000");
//    EPSyberosAlgo::testRegExp();

//    EPQml::interactionC();
////    EPSqlite::readFile();

//    QString domain = "phone";
//    qDebug()<<"====="<<domain.toLatin1().data();
//    QByteArray ba = domain.toLatin1();
//    const char* section = ba.data();
//    qDebug()<<__PRETTY_FUNCTION__<<domain.toStdString().c_str()<<section;

//    EPMateObject::execute();

//    QString str = "0";
//    bool backup = str.toInt();
//    qDebug()<<"backup "<<backup;

//    QString filename = "/home/xkd/tmp.txt";
//    QFile file(filename);
//    file.open(QFile::WriteOnly);
//    file.close();

//    bool value = -1;
//    qDebug()<<" ==== value  ===="<<value;


//    QFile file("backup");
//        if (!file.open(QIODevice::ReadOnly)) {
//            qDebug() << "Open file " << "for read failed!!!!!!!!!!";
////            return 1;
//        }
//    QDataStream srcStream(&file);
//    srcStream<<"xkd23423423423";

//    file.close();

//    QString length = "xingkongdao";
//    char* sms = (char*)malloc((1024)*sizeof(char));
//    char* tmp = new char[1024];
//    strcpy(sms,"xingkongdaoxingkogndaoxingkongdao");
//    qDebug()<<"sms===="<<strlen(sms)<<"tmp==="<<strlen(tmp);
//    qDebug()<<length.length()<<"========"<<length.toStdString().c_str()<<strlen(length.toStdString().c_str());
    qDebug()<<Q_FUNC_INFO<<QDateTime::currentDateTime();
    return app.exec();
}
