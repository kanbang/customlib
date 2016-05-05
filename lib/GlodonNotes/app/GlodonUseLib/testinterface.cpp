#include "testinterface.h"
#include <QDebug>

TestInterface::TestInterface()
{
}

void TestInterface::show()
{
    qDebug()<<__FUNCTION__;
}


Dialog::Dialog(QWidget *parent)
    :QDialog(parent)
{

}
