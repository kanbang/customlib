#include "EPlogAbstractModel.h"

EPlogAbstractModel::EPlogAbstractModel()
{
    m_rowCount = 4;
    m_columnCount = 4;
}

int EPlogAbstractModel::rowCount()
{
    return m_rowCount;
}

int EPlogAbstractModel::columnCount()
{
    return m_columnCount;
}

void EPlogAbstractModel::addRow()
{
    ++m_rowCount;
}

void EPlogAbstractModel::addColumn()
{
    ++m_columnCount;
}

void EPlogAbstractModel::removeColumn()
{
    --m_columnCount;
    if(m_columnCount < 0)
        m_columnCount = 0;
}

void EPlogAbstractModel::removeRow()
{
    --m_rowCount;
    if(m_rowCount < 0)
        m_rowCount = 0;
}

void EPlogAbstractModel::setHorizontalHeaderLabels(const QStringList &labels)
{
    m_columnNames = labels;
}

void EPlogAbstractModel::setVerticalHeaderLabels(const QStringList &labels)
{
    m_rowNames = labels;
}

QString EPlogAbstractModel::data(int rowIndex, int columnIndex)
{
    if(rowIndex == 0 || columnIndex == 0)
        return QString(" ( %1,%2 )").arg(rowIndex).arg(columnIndex);
    return QString(" ( %1,%2 )").arg(rowIndex).arg(columnIndex);

}
