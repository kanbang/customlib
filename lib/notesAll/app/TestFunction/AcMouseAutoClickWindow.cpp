#include "AcMouseAutoClickWindow.h"
#include "ui_AcMouseAutoClickWindow.h"
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <QShortcut>
#include <qxtglobalshortcut.h>

AcMouseAutoClickWindow::AcMouseAutoClickWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AcMouseAutoClickWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    ui->stopBtn->setEnabled(false);
    QShortcut *stopcut = new QShortcut(ui->stopBtn);
    QShortcut *begincut = new QShortcut(ui->beginBtn);
    stopcut->setContext(Qt::ApplicationShortcut);
//    begincut->setContext(Qt::ApplicationShortcut);
    stopcut->setKey(Qt::ALT + Qt::Key_T);
    begincut->setKey(Qt::ALT + Qt::Key_R);
    setAttribute(Qt::WA_KeyboardFocusChange);

    QxtGlobalShortcut * sc = new QxtGlobalShortcut(QKeySequence("Alt+R"), this);
    QxtGlobalShortcut * ss = new QxtGlobalShortcut(QKeySequence("Alt+T"), this);
    connect(sc, SIGNAL(activated()),this, SLOT(OnStopClick()));
    connect(ss,SIGNAL(activated()),this,SLOT(OnBeginClick()));
    connect(timer,SIGNAL(timeout()),this,SLOT(executeMousePress()));
    connect(ui->beginBtn,SIGNAL(clicked()),this,SLOT(OnBeginClick()));
    connect(ui->stopBtn,SIGNAL(clicked()),this,SLOT(OnStopClick()));
}

AcMouseAutoClickWindow::~AcMouseAutoClickWindow()
{
    delete ui;
}

void AcMouseAutoClickWindow::executeMousePress()
{
    static Display *display = 0;
    display = XOpenDisplay(NULL);
//    extern int XTestFakeButtonEvent(
//        Display*		/* dpy */,
//        unsigned int	/* button */, 1左键，2，中键，3，右键
//        Bool		/* is_press */,
//        unsigned long	/* delay */
//    );
    XTestFakeButtonEvent(display, 1, True, CurrentTime);
    XTestFakeButtonEvent(display, 1, False, CurrentTime);
    XFlush(display);
}

void AcMouseAutoClickWindow::OnStopClick()
{
    timer->stop();
    ui->stopBtn->setEnabled(false);
    ui->beginBtn->setEnabled(true);
}

void AcMouseAutoClickWindow::OnBeginClick()
{
    ui->stopBtn->setEnabled(true);
    ui->beginBtn->setEnabled(false);
    timer->start(ui->delaySbox->value());
    timer->setInterval(ui->intervalSbox->value());
}
