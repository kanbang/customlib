#include "TestWindowApp.h"
#include "ui_TestWindowApp.h"
#include <ETestHeader.h>
#include <QPropertyAnimation>

TestWindowApp::TestWindowApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestWindowApp)
{
    ui->setupUi(this);
    ui->applist->addItems(testFactoryProxy::getInstance()->getAppNameList());
    connect(ui->applist,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(run(QListWidgetItem*)));
}

TestWindowApp::~TestWindowApp()
{
    delete ui;
}

void TestWindowApp::run(QListWidgetItem *item)
{
//    QPropertyAnimation* anim = new QPropertyAnimation(this,"size");
//    anim->setDuration(5000);
//    anim->setStartValue(QSize(width(),height()));
//    anim->setEndValue(QSize(0,height()));
//    anim->start();
//    ui->applist->hide();
    testAbstractFactory* factory = testFactoryProxy::getInstance()->getFactory(item->text());
    if(factory)
        factory->run();
}
