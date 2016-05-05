#ifndef ACTHREADWINDOWAPP_H
#define ACTHREADWINDOWAPP_H

#include <QMainWindow>
#include <ETAllHeader.h>

class AcThread : public QThread
{
    Q_OBJECT

public:
    AcThread(QWidget* pW,QMutex *mu);

protected:
    void run();

public slots:
    void show();

signals:
    void showValue();

private:
    QWidget *m_pW;
    QMutex *mutex;
};

class AcLineEdit   : public QLineEdit
{
    Q_OBJECT

public:
    AcLineEdit(QWidget *parent = 0);

    bool event(QEvent *);
};

class AcThreadWindowApp : public QWidget
{
    Q_OBJECT
public:
    explicit AcThreadWindowApp(QWidget *parent = 0);
    void emitSignal();

    QString str;
    bool ab;
    int _val;

    bool event(QEvent *event);

signals:
    void valueChanged();

public slots:
    void slotThreadA();
    void slotThreadB();
    void showData();

private:
    AcThread* threadA;
    AcThread* threadB;
    QPushButton * btnA, *btnB;
};

#endif // ACTHREADWINDOWAPP_H
