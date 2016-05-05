#ifndef CLTABLEMODEL_H
#define CLTABLEMODEL_H

#include <QAbstractTableModel>
#include "CLDatabase.h"
#include <QMap>

class CLTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit CLTableModel(QObject *parent = 0);
 
	int columnCount(const QModelIndex &parent) const;
	int rowCount(const QModelIndex &parent) const;
	QVariant data(const QModelIndex &index, int role) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role) const;
	QModelIndex index(int row, int column, const QModelIndex &parent) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;

signals:
    
public slots:
    
private:
    QMap<int, QStringList> m_maps;
};

#endif // CLTABLEMODEL_H
