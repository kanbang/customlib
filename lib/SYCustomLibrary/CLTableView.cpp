#include "CLTableView.h"
#include "CLTableModel.h"

CLTableView::CLTableView(QWidget *parent)
    :QTableView(parent)
{
    setModel(new CLTableModel(this));
    setColumnWidth(0,200);
    setColumnWidth(1,200);
    setColumnWidth(3,300);
    sortByColumn(2,Qt::AscendingOrder);
    setSortingEnabled(true);
    setSpan(1,0,23,2);
//    setShowGrid(false);
}
