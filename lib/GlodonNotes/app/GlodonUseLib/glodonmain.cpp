#include <QApplication>
#include <GlodonTestWidget.h>
#include <GlodonForm.h>
#include <GlodonModelView.h>
#include <GlodonModel.h>
#include <GlodonTestGrammar.h>
#include <QLibrary>
#include <QDebug>
#include <QListView>
#include <QHash>
#include <SharedLib.h>
#include <GlodonGuideTipFrame.h>
#include "GlodonModelView.h"
#include "GlodonTreeView.h"
#include "GlodonPattern.h"
#include "testinterface.h"
#include "GlodonThread.h"
#include "GlodonSmartPointer.h"

typedef int (*pFunc)(int ,int);

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);

    qDebug()<<__FUNCTION__<<qApp->applicationDirPath();
    QLibrary lib("D:/program/lib/testlib.dll");
    if(lib.load())
    {
        pFunc pf = (pFunc)lib.resolve("add");
        if(pf != NULL)
        {
            qDebug()<<pf(3,2);
        }
    }

//    GlodonTestGrammar::testProcess();
    GlodonTestGrammar::testTextStream();

    QString str = "(123";
    qDebug()<<__FUNCTION__<< str.mid(str.indexOf("(12"),2)<<c_n2222RGb.at(1);
    return app.exec();
}
