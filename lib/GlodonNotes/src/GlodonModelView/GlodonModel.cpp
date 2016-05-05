#include "GlodonModel.h"
#include <QStringList>
#include <QSpinBox>
#include <QPainter>

GlodonTableModel::GlodonTableModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int GlodonTableModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

int GlodonTableModel::rowCount(const QModelIndex &parent) const
{
    return 4;
}
QVariant GlodonTableModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
        return QString("xkd");
    else
        return QVariant();
}

QModelIndex GlodonTableModel::index(int row, int column, const QModelIndex &parent) const
{
    if (row < 0 || column < 0 || row >= rowCount(parent) || column >= columnCount(parent))
        return QModelIndex();
    return createIndex(row, column);
}

GlodonListModel::GlodonListModel(QObject *parent) : QAbstractListModel(parent)
{

}

int GlodonListModel::rowCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant GlodonListModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
        return QString("xkd");
}



EPItemModel::EPItemModel(const QStringList &list, QObject *parent) :
    QAbstractItemModel(parent), _list(list)
{
    _ints <<1<<2<<3<<4<<5<<6;
}

int EPItemModel::rowCount(const QModelIndex &parent) const
{
    return _list.count();
}

int EPItemModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant EPItemModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(index.row() >= _ints.size())
        return QVariant();

    QString str = "xkd";
    if(role == Qt::DisplayRole)
        return str;
    if(role == Qt::DisplayRole)
        return _ints.at(index.row());
    else
        return QVariant();

}

bool EPItemModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    _ints[index.row()] = value.toInt();
    QModelIndex topLeft(this->index(index.row(),0,QModelIndex()));
    QModelIndex bottomRight(this->index(index.row(),columnCount(QModelIndex()),QModelIndex()));
    emit dataChanged(topLeft,bottomRight);
    return true;
}

QModelIndex EPItemModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

QModelIndex EPItemModel::index(int row, int column, const QModelIndex &parent) const
{
    if(row < 0 || column < 0)
        return QModelIndex();
    else
        return createIndex(row,column);
}

Qt::ItemFlags EPItemModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}


/************************
**  EPListModel
**/
EPListModel::EPListModel(QObject *parent) : QAbstractListModel(parent)
{
    _list<<"one"<<"two"<<"three"<<"four";
}

int EPListModel::rowCount(const QModelIndex &parent) const
{
    return _list.count();
}

QVariant EPListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(index.row() >= _list.size())
        return QVariant();

    if(role == Qt::EditRole)
        return _list.at(index.row());

    else if (role == Qt::DisplayRole)
        return _list.at(index.row());

    else
        return QVariant();
}

EPItemDelegate::EPItemDelegate(QObject *parent) : QItemDelegate(parent)
{

}

QWidget* EPItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox* editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(100);
    return editor;
}

void EPItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::DisplayRole).toInt();
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->setValue(value);
}

void EPItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinBox = static_cast<QSpinBox*> (editor);
    spinBox->interpretText();
    int value = spinBox->value();
    model->setData(index,value);
}

void EPItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

void EPItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.row() == 0)
        painter->fillRect(option.rect,QBrush(Qt::darkBlue));
    else if (index.row() == 1)
        painter->fillRect(option.rect,QBrush(Qt::darkCyan));
    else if (index.row() == 2)
        painter->fillRect(option.rect,QBrush(Qt::darkGray));
    else if (index.row() == 3)
        painter->fillRect(option.rect,QBrush(Qt::darkYellow));

    QItemDelegate::paint(painter,option,index);
}

