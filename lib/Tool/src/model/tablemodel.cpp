#include <managerdb.h>
#include <tabledata.h>
#include "tablemodel.h"
#include <QDebug>

TableModel::TableModel(const QString &tableName, QObject *parent) :
    QAbstractTableModel(parent),
    tData(NULL)
{
    m_mgrDB = new ManagerDB("/home/xkd/tmp","harassment.db");
    setTableName(tableName);
}

void TableModel::setTableName(const QString &name)
{
    beginResetModel();
    tData = m_mgrDB->tableData(name);
    endResetModel();
}

QStringList TableModel::tableNames() const
{
    return m_mgrDB->tableNames();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
//    qDebug()<<Q_FUNC_INFO<<tData;
    return tData ? tData->columnCount() : 0;
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    return tData ? tData->rowCount() : 0;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    bool hasData = (!index.isValid()) || (!tData);
    if(hasData)
        return QVariant();

    if(role == Qt::DisplayRole)
    {
        return tData->data(index.row(), index.column());
    }
    else
    {
        return QVariant();
    }
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{

    return QAbstractTableModel::flags(index);
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(!tData)
        return QVariant();

    QStringList fields = tData->fieldNames();
    if( section >= fields.count())
        return QVariant();

    if(orientation == Qt::Horizontal)
    {
        if(role == Qt::DisplayRole)
        {
            return fields[section];
        }
        else
        {
            return QVariant();
        }
    }
    return QVariant();
}
