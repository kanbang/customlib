#include "threadWindowApp.h"
#include "ui_threadWindowApp.h"

threadWindowApp::threadWindowApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::threadWindowApp)
{
    ui->setupUi(this);
    ui->applist->addItems(threadFactoryProxy::getInstance()->getAppNameList());
    connect(ui->applist, SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(run(QListWidgetItem*)));
}

threadWindowApp::~threadWindowApp()
{
    delete ui;
}

void threadWindowApp::run(QListWidgetItem *item)
{
    threadAbstractFactory* factory = threadFactoryProxy::getInstance()->getFactory(item->text());
    if(factory)
        factory->run();

    emit emitSignal();
}
