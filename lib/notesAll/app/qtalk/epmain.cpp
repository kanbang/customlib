#include<QApplication>
#include<AaServerWindowApp.h>
#include <AaClientWindowApp.h>
#include <EPAlgorithm.h>
#include <EPOutBlockDatastream.h>
#include <EPmapView.h>
#include <EPMainWindow.h>
#include <DefineType.h>
#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
//        AaServerWindowApp w;
//        w.show();

        AaClientWindowApp App;
        App.show();

    return app.exec();
}
