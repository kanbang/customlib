#ifndef EPMODEL_H
#define EPMODEL_H

#include <QAbstractItemModel>
#include <QStringList>
#include <QItemDelegate>

class EPItemModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit EPItemModel(const QStringList &list, QObject *parent = 0);
    int columnCount(const QModelIndex &parent) const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QModelIndex parent(const QModelIndex &child) const;
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    QStringList _list;
    QList<int> _ints;
};

class EPListModel : public QAbstractListModel
{
public:
    explicit EPListModel(QObject* parent = 0);
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    QStringList _list;
};

class EPItemDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    EPItemDelegate(QObject *parent  = 0);
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // EPMODEL_H
