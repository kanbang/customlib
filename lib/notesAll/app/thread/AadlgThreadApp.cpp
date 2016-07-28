#include "AadlgThreadApp.h"
#include <ETAllHeader.h>

AadlgThreadApp::AadlgThreadApp(QWidget *parent) :
    QDialog(parent)
{
    threadA.setMessage("aAc");
    threadB.setMessage("bBl");

    threadAButton = new QPushButton(tr("Start A"));
    threadBButton = new QPushButton(tr("Start B"));
    quitButton = new QPushButton(tr("Quit"));
    quitButton->setDefault(true);

    connect(threadAButton, SIGNAL(clicked()),
            this, SLOT(startOrStopThreadA()));
    connect(threadBButton, SIGNAL(clicked()),
            this, SLOT(startOrStopThreadB()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(threadAButton);
    mainLayout->addWidget(threadBButton);
    mainLayout->addWidget(quitButton);
    setLayout(mainLayout);

    setWindowTitle(tr("Threads"));

//    QString strs[] = {"xingkongdao","zhengsihua","darling girl"};
//    qDebug()<<sizeof(strs)/sizeof(QString);
}

void AadlgThreadApp::startOrStopThreadA()
{
    if (threadA.isRunning()) {
        threadA.stop();
        threadAButton->setText(tr("Start AA"));
    } else {
        threadA.start();
        threadAButton->setText(tr("Stop AB"));
    }
}

void AadlgThreadApp::startOrStopThreadB()
{
    if (threadB.isRunning()) {
        threadB.stop();
        threadBButton->setText(tr("Start BB"));
    } else {
        threadB.start();
        threadBButton->setText(tr("Stop BA"));
    }
}

void AadlgThreadApp::closeEvent(QCloseEvent *event)
{
    threadA.stop();
    threadB.stop();
//    threadA.wait();
//    threadB.wait();
    event->accept();
}
