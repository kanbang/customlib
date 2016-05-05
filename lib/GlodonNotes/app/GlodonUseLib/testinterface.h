#ifndef TESTINTERFACE_H
#define TESTINTERFACE_H

#include "GlodonInterface.h"
#include <QDialog>

class TestInterface : public GInterface
{
public:
    TestInterface();
    void show();
};

class Dialog : public QDialog
{
public:
    Dialog(QWidget* parent = 0);
};

#endif // TESTINTERFACE_H
