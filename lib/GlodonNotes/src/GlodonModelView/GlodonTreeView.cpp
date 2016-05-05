#include "GlodonTreeView.h"

GlodonTreeView::GlodonTreeView(QWidget *parent) :
    QTreeView(parent)
{
    GlodonTreeModel *model = new GlodonTreeModel(this);
    setModel(model);
}


GlodonTreeModel::GlodonTreeModel(QObject *parent) : QAbstractItemModel(parent)
{

}

int GlodonTreeModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

int GlodonTreeModel::rowCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant GlodonTreeModel::data(const QModelIndex &index, int role) const
{
    return QString("xkd");
}

bool GlodonTreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return true;
}

QModelIndex GlodonTreeModel::parent(const QModelIndex &child) const
{
    return child.parent();
}

QModelIndex GlodonTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    return parent.child(row,column);
}

Qt::ItemFlags GlodonTreeModel::flags(const QModelIndex &index) const
{
    return index.flags();
}


ListModel::ListModel(QObject *parent) : QAbstractListModel(parent)
{

}

int ListModel::rowCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(index.row() > 3 )
        return QVariant();

    if(role == Qt::DisplayRole)
        return QVariant("xingkd");
    else if (role == Qt::EditRole)
        return QVariant("zhengsh");
    else if (role == Qt::ToolTipRole)
        return QVariant("xkd");
    else
        return QVariant();
}

bool ListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return true;
}

Qt::ItemFlags ListModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | Qt::ItemIsEnabled;
//    return(QAbstractListModel::flags(index))&~(Qt::ItemIsEnabled);
}



#include "GlodonModel.h"
ListView::ListView(QWidget *parent) : QListView(parent)
{
    ListModel *model = new ListModel(this);
    setModel(model);
}
