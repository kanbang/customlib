#include <QListView>
#include <QApplication>
#include <QDebug>
#include <EPDBus.h>
#include <EPQml.h>
#include <EPSqlite.h>
#include <EPSyberosAlgo.h>
#include <SyMatchNumber.h>
#include <EPModel.h>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);


//    EPSyberosAlgo::matchPhoneNumber("4008880000");
//    EPSyberosAlgo::testRegExp();

//    EPQml::interactionC();
//    EPSqlite::readFile();

    QString domain = "phone";
    QVariant list(QStringList()<<"1"<<"2"<<"3");
//    QByteArray ba = domain.toLatin1();
//    const char* section = ba.data();
    qDebug()<<domain.toLatin1().data() << list;
    return app.exec();
}
