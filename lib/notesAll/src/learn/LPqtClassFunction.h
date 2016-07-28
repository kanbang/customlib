#ifndef LPQTCLASSFUNCTION_H
#define LPQTCLASSFUNCTION_H

#include <QItemDelegate>

class LPqtClassFunction
{
public:
    LPqtClassFunction();
    void mutex();
    void object();
    void painterPath();
    void widget();
    void painter();
    void dir();
    void undoCommand();
    void settings();
    void string();
    // model/view 模块
    void modelView();

    //QtSql 数据库模块
    void qsql();
};

class Delegate : public QItemDelegate
{
public:
    Delegate(QObject* parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // LPQTCLASSFUNCTION_H
