#include "EPlogTable.h"
#include <EPlogAbstractModel.h>
#include <QPainter>
#include <QRectF>

void EPlogTableItem::paint(QPainter *painter, QWidget *view)
{
    painter->save();
    QMatrix affine = painter->worldMatrix();
    painter->setWorldMatrixEnabled(false);
//    QRect posRect = affine.mapRect(m_bbox).toRect();
    QRect posRect = m_bbox;
    painter->drawRect(posRect);
    painter->drawText(posRect,Qt::AlignCenter,m_valueString);
    painter->restore();
}

EPlogTable::EPlogTable()
{
    m_model = new EPlogAbstractModel();
    m_rowNames<<"first"<<"second"<<"third"<<"fourth";
    m_columnNames = m_rowNames;
    newlogTableItem();
}

void EPlogTable::setModel(EPlogAbstractModel *model)
{
    if(m_model)
        delete m_model;
    m_model = model;
}

void EPlogTable::append(EPlogTableItem *item)
{
    m_childItems.append(item);
}

void EPlogTable::remove(EPlogTableItem *item)
{
    m_childItems.removeOne(item);
}

void EPlogTable::paint(QPainter *painter, QWidget *view)
{
    foreach(EPlogTableItem* item, m_childItems)
    {
        item->paint(painter,view);
    }
}

void EPlogTable::drawForeground(QPainter *painter, QWidget *view)
{
    painter->save();
    QPen pen(Qt::red);
    pen.setWidth(3);
    pen.setStyle(Qt::DashDotLine);
    painter->setPen(pen);
    painter->drawRect(m_focusRect);
    painter->restore();
}

void EPlogTable::setFocusRect(QRect rect)
{
    m_focusRect = rect;
}

void EPlogTable::setRect(QRect rect)
{
    m_bbox = rect;
}

void EPlogTable::calPos()
{
    int width = m_bbox.width()/(m_model->columnCount()+1);
    int height = m_bbox.height()/(m_model->rowCount()+1);
    for(int i = -1; i < m_model->rowCount(); i++)
        for(int j = -1; j < m_model->columnCount(); j++)
        {
            EPlogTableItem* item = getTableItem(i,j);
            if( !item )
                return ;
            item->m_bbox = QRect(m_bbox.topLeft() + QPoint(width*(j+1),height*(i+1))
                                 ,QSize(width,height));
            if(i == -1 || j == -1)
            {
                item->m_valueString = getTitle(i,j);
            } else
//            item->m_valueString = QString("( %1,%2 )").arg(item->m_rowIndex).arg(item->m_columnIndex);
                item->m_valueString = m_model->data(i,j);
        }
}

#include <QDebug>

QString EPlogTable::getTitle(int rowIndex, int columnIndex)
{
    if(rowIndex == -1 && columnIndex == -1)
    {
        return QString();
    } else if (rowIndex == -1 && columnIndex != -1)
    {
        if(m_columnNames.isEmpty())
            return QString();
        else
            return m_columnNames.at(columnIndex);
    } else if(rowIndex != -1 && columnIndex == -1)
    {
        if(m_rowNames.isEmpty())
            return QString();
        else
            return m_rowNames.at(rowIndex);
    }
}

EPlogTableItem* EPlogTable::getTableItem(int rowIndex, int columnIndex)
{
    foreach(EPlogTableItem* item, m_childItems)
    {
        if(item->m_rowIndex == rowIndex && item->m_columnIndex == columnIndex)
            return item;
    }
    return 0;
}

void EPlogTable::newlogTableItem()
{
    qDeleteAll(m_childItems.begin(),m_childItems.end());
    m_childItems.clear();
    for(int i = -1; i < m_model->rowCount(); i++)
        for(int j = -1; j< m_model->columnCount(); j++)
        {
            EPlogTableItem* item = new EPlogTableItem();
            item->m_rowIndex = i;
            item->m_columnIndex = j;
            append(item);
        }
}

void EPlogTable::insertColumn(int before, QString columnName)
{
    m_model->addColumn();
    m_columnNames.insert(before,columnName);
    newlogTableItem();
}

void EPlogTable::insertRow(int before, QString rowName)
{
    m_model->addRow();
    m_rowNames.insert(before,rowName);
    newlogTableItem();
}

void EPlogTable::removeColumn(int column)
{
    m_model->removeColumn();
    if(m_columnNames.count() >= column)
        m_columnNames.removeAt(column);
    newlogTableItem();
}

void EPlogTable::removeRow(int row)
{
    m_model->removeRow();
    if(m_rowNames.count() >= row)
        m_rowNames.removeAt(row);
    newlogTableItem();
}

void EPlogTable::setHorizontalHeaderLabels(const QStringList &labels)
{
    m_columnNames = labels;
}

void EPlogTable::setVerticalHeaderLabels(const QStringList &labels)
{
    m_rowNames = labels;
}
