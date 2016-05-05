#include "TreeWidget.h"
//#include <QWindowsStyle>

TreeWidget::TreeWidget(QWidget *parent) :
    QTreeWidget(parent)
{
    /**
    \brief
    QTreeWidgetItem::setText(int column, QSring str);
    这里的column是根据 setColumnCount()这个函数来的。
     */
    this->setColumnCount(2);
    QStringList lists;
    lists<<"name"<<"value";
    setHeaderLabels(lists);
    init();
//    setStyle(new QWindowsStyle()); //设置风格，windows style, mac style
    setState(QAbstractItemView::ExpandingState);
}

void TreeWidget::init()
{
    QTreeWidgetItem* pItemA = new QTreeWidgetItem(0);
    pItemA->setText(0,"A");
    QTreeWidgetItem* pItemB = new QTreeWidgetItem(1);
    pItemB->setText(0,"B");
    QTreeWidgetItem* pItemC = new QTreeWidgetItem(2);
    pItemC->setText(0,"C");
    QTreeWidgetItem* pItemAa = new QTreeWidgetItem(3);
    pItemAa->setText(0,"Aa");
    pItemAa->setText(1,"100");
    QTreeWidgetItem* pItemAb = new QTreeWidgetItem(4);
    pItemAb->setText(0,"Ab");
    pItemAb->setText(1,"200");
    QTreeWidgetItem* pItemBa = new QTreeWidgetItem(5);
    pItemBa->setText(0,"Ba");
    QTreeWidgetItem* pItemAaa = new QTreeWidgetItem(1);
    pItemAaa->setText(1,"Aaa");

    addTopLevelItem(pItemA);
    pItemA->addChild(pItemAa);
    pItemA->addChild(pItemAb);

    addTopLevelItem(pItemB);
    pItemB->addChild(pItemBa);

    addTopLevelItem(pItemC);

    pItemAa->addChild(pItemAaa);
    setItemsExpandable(true);
}
