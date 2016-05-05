#ifndef EPLOGTABLE_H
#define EPLOGTABLE_H
#include <EPlogAbstractModel.h>
#include <QWidget>

class EPlogTableItem
{
public:
    void paint(QPainter *painter, QWidget *view);

    int m_rowIndex;
    int m_columnIndex;
    QString m_rowName;
    QString m_columnName;
    QString m_valueString;
    QRect   m_bbox;
};

class EPlogTable
{
public:
    EPlogTable();

    void setModel(EPlogAbstractModel* model);
    void newlogTableItem();
    void removeRow(int row);
    void removeColumn(int column);
    void insertRow(int before,QString rowName);
    void insertColumn(int before, QString columnName);
    void setHorizontalHeaderLabels ( const QStringList & labels );
    void setVerticalHeaderLabels ( const QStringList & labels );

    void append(EPlogTableItem* item);
    void remove(EPlogTableItem* item);

    void paint(QPainter* painter, QWidget* view);
    void drawForeground(QPainter* painter, QWidget* view);
    void setRect(QRect rect);
    void setFocusRect(QRect rect);
    void calPos();
    QString getTitle(int rowIndex, int columnIndex);
    EPlogTableItem* getTableItem(int rowIndex, int columnIndex);

private:
    EPlogAbstractModel* m_model;
    QStringList         m_rowNames;
    QStringList         m_columnNames;
    QList<EPlogTableItem*> m_childItems;
    QRect               m_bbox;
    QRect               m_focusRect;
};

#endif // EPLOGTABLE_H
