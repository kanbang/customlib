#ifndef AADLGTHREADAPP_H
#define AADLGTHREADAPP_H

#include <QDialog>
#include <MuteThread.h>

class AadlgThreadApp : public QDialog
{
    Q_OBJECT
public:
    explicit AadlgThreadApp(QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    //如果不是用线程，那么当按下A时，就会一直无限循环，再按B时，因为A一直无限循环，所以B 会没有响应。
    //而如果用线程就可以。
    void startOrStopThreadA();
    void startOrStopThreadB();

private:
    MuteThread threadA;
    MuteThread threadB;
    QPushButton *threadAButton;
    QPushButton *threadBButton;
    QPushButton *quitButton;
};

#endif // AADLGTHREADAPP_H
