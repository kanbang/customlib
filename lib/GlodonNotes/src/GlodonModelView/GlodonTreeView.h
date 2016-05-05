#ifndef GLODONTREEVIEW_H
#define GLODONTREEVIEW_H

#include <QTreeView>
#include "glodonmodelview_global.h"
#include <QAbstractItemModel>
#include <QListView>
#include <QAbstractListModel>

class GLODONMODELVIEWSHARED_EXPORT GlodonTreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit GlodonTreeView(QWidget *parent = 0);

signals:

public slots:

};

class GLODONMODELVIEWSHARED_EXPORT GlodonTreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    GlodonTreeModel(QObject *parent = 0);

    int columnCount(const QModelIndex &parent) const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QModelIndex parent(const QModelIndex &child) const;
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
};

class GLODONMODELVIEWSHARED_EXPORT ListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    ListModel(QObject *parent =0);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
};

class GLODONMODELVIEWSHARED_EXPORT ListView : public QListView
{
    Q_OBJECT

public:
    ListView(QWidget* parent = 0);

};

#endif // GLODONTREEVIEW_H
