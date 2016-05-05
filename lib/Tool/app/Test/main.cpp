
#include<QApplication>
#include <QTableView>
#include <tablemodel.h>
#include "DisplayTableForm.h"
#include <ccontactdb.h>
#include <stringutility.h>
#include <utility.h>

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);

//    DisplayTableForm form;
//    form.show();
    QString str = "=E5=8D=8E=E4=B8=BA";//;=E6=9C=8D;=E5=AE=A2";
    QString decoded = stringUtility::decode_quote_qprintable(str);
    qDebug()<<decoded;

    stringUtility::initPinyinMap();

    for(int i = 0; i<decoded.count(); i++)
    {
        qDebug()<<stringUtility::getPinyinString(decoded.at(i));
    }


    QString str1 = "常as";

    unsigned short begin = 0x4E00;
    unsigned short end=0x9FCB;

    for(int i = 0; i<str1.count(); i++)
    {
        QChar ch = str1.at(i);
        stringUtility::getPinyinChar(ch);
    }

    return 0;//app.exec();
}
