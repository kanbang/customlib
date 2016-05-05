#include "networkWindowApp.h"
#include "ui_networkWindowApp.h"
#include <QMouseEvent>
#include<QtTest/QTest>
using namespace QTest;
//#include <EPSingleton.h>
#include <cfunction/EPCFunction.h>
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>

networkWindowApp::networkWindowApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::networkWindowApp)
{
    ui->setupUi(this);
    ui->applist->addItems(networkFactoryProxy::getInstance()->getAppNameList());
    connect(ui->applist,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(run(QListWidgetItem*)));

    //timer = new QTimer(this);
    //timer->start(100);
    //connect(timer,SIGNAL(timeout()),this,SLOT(mouseClick()));
//    ui->applist->setSelectionMode(QAbstractItemView::MultiSelection);
//    testIdea();
}

networkWindowApp::~networkWindowApp()
{
    delete ui;
}

void networkWindowApp::mousePressEvent(QMouseEvent *e)
{
    qDebug()<<__PRETTY_FUNCTION__;
    QWidget *widget = qApp->widgetAt(e->pos());
//    widget->activateWindow();
}

void networkWindowApp::initAppList()
{
    applist.clear();
    applist<<tr("AadlgClientApp")<<tr("AadlgServerApp")<<tr("AbdlgUdpApp")
          <<tr("AbFtpApp")<<tr("AbFtpExtendApp")<<tr("AbHttpApp")<<tr("AbUdpWidgetApp")
         <<tr("AClientWidgetApp")<<tr("AcTcpServerWindowApp")<<tr("AServerWidgetApp");
}

void networkWindowApp::testIdea()
{
    EPCFunction::memcpyTest();
}

void networkWindowApp::run(QListWidgetItem *item)
{
    networkAbstractFactory* factory = networkFactoryProxy::getInstance()->getFactory(item->text());
    if(factory)
        factory->run();
}
void networkWindowApp::mouseClick()
{
//    QMouseEvent* press=new QMouseEvent(QEvent::MouseButtonPress,QPoint(0,0), Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
//    QApplication::postEvent(this,press);
//    QMouseEvent* release=new QMouseEvent(QEvent::MouseButtonRelease,QPoint(0,0),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
//    QApplication::postEvent(this,release);
////    QDesktopWidget w;

//    QMouseEvent event(QEvent::MouseButtonPress,w.pos(),Qt::NoButton,Qt::NoButton,Qt::NoModifier);
//    QApplication::sendEvent(this,&event);
}

