#ifndef ABSHAREMEMORYWIDGETAPP_H
#define ABSHAREMEMORYWIDGETAPP_H
#include <QWidget>
#include <ETAllHeader.h>

class ShareMemoryLoad:public QWidget
{
    Q_OBJECT

public:
    ShareMemoryLoad(QWidget *parent=0);
    ~ShareMemoryLoad();

private:
    QSharedMemory sharedMem;
    void loadIntoSharedMem();
};

class ShareMemoryShow:public QWidget
{
    Q_OBJECT

public:
    ShareMemoryShow(QWidget *parent=0);
    ~ShareMemoryShow();

private:
    QSharedMemory sharedMem;
    void showIntoSharedMem();
};

#endif // ABSHAREMEMORYWIDGETAPP_H
