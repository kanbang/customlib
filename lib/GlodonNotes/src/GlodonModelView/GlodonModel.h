#ifndef GLODONMODEL_H
#define GLODONMODEL_H

#include <QAbstractTableModel>
#include <glodonmodelview_global.h>
#include <QAbstractItemModel>
#include <QStringList>
#include <QItemDelegate>

class GLODONMODELVIEWSHARED_EXPORT GlodonTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    GlodonTableModel(QObject* parent = 0);

    virtual int	columnCount(const QModelIndex & parent = QModelIndex()) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    virtual QModelIndex	index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
//    virtual QModelIndex	parent(const QModelIndex & index) const;
};

class GLODONMODELVIEWSHARED_EXPORT GlodonListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    GlodonListModel(QObject* parent = 0);

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
};


class GLODONMODELVIEWSHARED_EXPORT EPItemModel : public QAbstractItemModel
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

class GLODONMODELVIEWSHARED_EXPORT EPListModel : public QAbstractListModel
{
public:
    explicit EPListModel(QObject* parent = 0);
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    QStringList _list;
};

class GLODONMODELVIEWSHARED_EXPORT EPItemDelegate : public QItemDelegate
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

#endif // GLODONMODEL_H
