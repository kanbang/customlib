#ifndef EPLOGABSTRACTMODE_H
#define EPLOGABSTRACTMODE_H
#include <QString>
#include <QStringList>

class EPlogAbstractModel
{
public:
    EPlogAbstractModel();

    int rowCount();
    int columnCount();
    void addRow();
    void addColumn();
    void removeRow();
    void removeColumn();
    virtual QString data(int rowIndex,int columnIndex);
    void setHorizontalHeaderLabels ( const QStringList & labels );
    void setVerticalHeaderLabels ( const QStringList & labels );

private:
    int m_rowCount;
    int m_columnCount;
    QStringList         m_rowNames;
    QStringList         m_columnNames;
};

#endif // EPLOGABSTRACTMODE_H
