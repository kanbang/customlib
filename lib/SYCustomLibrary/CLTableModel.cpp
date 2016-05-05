#include "CLTableModel.h"

CLTableModel::CLTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    CLDatabase db;
    m_maps = db.getTable();
}

int CLTableModel::columnCount(const QModelIndex& parent) const
{
    return m_maps[0].count();
}

int CLTableModel::rowCount(const QModelIndex& parent) const
{
    return m_maps.count();
}

QVariant CLTableModel::data(const QModelIndex& parent, int role) const
{
    QString value = m_maps[parent.row()].at(parent.column());

	if( role == Qt::DisplayRole )
    {
        return value;
    }
    else if (role == Qt::EditRole)
    {
        return "zhengsihua";
    }
	else
		return "xkd";

}

bool CLTableModel::setData(const QModelIndex& parent, const QVariant& value, int role) const 
{
	int i = 0; 
	return false;
}

QModelIndex CLTableModel::index(int row, int column, const QModelIndex& parent) const
{
	return QAbstractTableModel::index(row, column, parent);
}

Qt::ItemFlags CLTableModel::flags(const QModelIndex& parent) const 
{
    return  Qt::ItemIsEditable |Qt::ItemIsEnabled |Qt::ItemIsSelectable;
}


