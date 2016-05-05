#include "EPModel.h"
#include <QStringList>
#include <QSpinBox>
#include <QPainter>

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
    /**
    enum ItemDataRole {
        DisplayRole = 0,
        DecorationRole = 1,
        EditRole = 2,
        ToolTipRole = 3,
        StatusTipRole = 4,
        WhatsThisRole = 5,
        // Metadata
        FontRole = 6,
        TextAlignmentRole = 7,
        BackgroundColorRole = 8,
        BackgroundRole = 8,
        TextColorRole = 9,
        ForegroundRole = 9,
        CheckStateRole = 10,
        // Accessibility
        AccessibleTextRole = 11,
        AccessibleDescriptionRole = 12,
        // More general purpose
        SizeHintRole = 13,
        InitialSortOrderRole = 14,
        // Internal UiLib roles. Start worrying when public roles go that high.
        DisplayPropertyRole = 27,
        DecorationPropertyRole = 28,
        ToolTipPropertyRole = 29,
        StatusTipPropertyRole = 30,
        WhatsThisPropertyRole = 31,
        // Reserved
        UserRole = 32
    };

    获取data时，每一个Item，有很多role属性，比如SizeHintRole，是可以用来设置Item的宽高的。
    DisplayRole 是用来设置Item显示的内容的。如果不需要特定设置，则可以返回QVariant();
    如果返回的是别的值，会导致其他的代码分支失效。
      */
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

