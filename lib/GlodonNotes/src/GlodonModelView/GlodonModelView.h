#ifndef GLODONMODELVIEW_H
#define GLODONMODELVIEW_H

#include "glodonmodelview_global.h"
#include <QTableView>
#include <QTreeView>

class GLODONMODELVIEWSHARED_EXPORT GlodonModelView : public QTableView
{
    Q_OBJECT

public:
    GlodonModelView(QWidget *parent = 0);

    void staticDirModel();
};

class GLODONMODELVIEWSHARED_EXPORT View : public QTreeView
{
    Q_OBJECT

public:
    View(QWidget* parent = 0);
};

#endif // GLODONMODELVIEW_H
