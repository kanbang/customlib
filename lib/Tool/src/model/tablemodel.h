#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include "EPModel_global.h"

class TableData;
class ManagerDB;
class MODEL_EXPORT TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TableModel(const QString& tableName, QObject *parent = 0);
    void setTableName(const QString& name);
    QStringList tableNames() const;
    int columnCount(const QModelIndex &parent) const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

signals:

public slots:

private:
    TableData* tData;
    ManagerDB* m_mgrDB;
};

#endif // TABLEMODEL_H
