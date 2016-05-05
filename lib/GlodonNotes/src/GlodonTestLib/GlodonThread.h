#ifndef GLODONTHREAD_H
#define GLODONTHREAD_H

#include <QThread>
#include "glodontestlib_global.h"

class WIDGETSHARED_EXPORT GlodonThread : public QThread
{
    Q_OBJECT
public:
    explicit GlodonThread(QObject *parent = 0);

    void run();
};

#endif // GLODONTHREAD_H
