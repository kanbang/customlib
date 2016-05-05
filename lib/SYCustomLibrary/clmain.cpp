#include <QApplication>
#include "CLTableView.h"
#include <QThread>
#include <QTimer>
#include "CLDatabase.h"
#include <QStyleFactory>

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);
//    app.setStyle("windows");
    QApplication::setStyle("motif");

    CLTableView *view = new CLTableView();
	
    view->setWindowTitle("Display Database");
    view->resize(800,600);
    view->show();

//    CLDatabase::createDb(QString());

    return app.exec();
}
