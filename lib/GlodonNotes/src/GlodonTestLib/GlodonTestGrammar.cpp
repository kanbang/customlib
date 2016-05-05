#include "GlodonTestGrammar.h"
#include <QDebug>
#include <QTableView>
#include <QStringList>
#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDir>
#include <QLineEdit>
#include <QCompleter>
#include "GlodonTestWidget.h"
#include "GlodonModel.h"
#include <QProcess>
#include <QMenu>
//string = "xkd";

GlodonTestGrammar::GlodonTestGrammar()
{
}

void GlodonTestGrammar::testPair()
{
    QPair<double,double> pair;
    pair.first = 3.03;
    pair.second = 55.33;

    qDebug()<<pair.first <<pair.second;

    GlodonTableModel* model = new GlodonTableModel();
}

void GlodonTestGrammar::testHashRemove()
{
    QHash<QString, int*> hash;

    int *p = new int(10);
    int *p1 = new int(20);
    int *p2 = new int(30);
    hash["one"] = p;
    hash["three"] = p1;
    hash["seven"] = p2;
    hash.remove("one");
    qDebug()<<*p << hash.count();
}

void GlodonTestGrammar::testVariant()
{
    QVariant var("");
    /**
      0 , true , "" , false
      */
    qDebug()<<var.toInt()<<var.isNull() << var.toString()<<var.toBool();
}
#include <QMainWindow>
#include <QComboBox>
#include <QObject>
#include <QPushButton>
void GlodonTestGrammar::testStackWidget()
{
    QMainWindow* mainWindow = new QMainWindow();

    QWidget *firstPageWidget = new QPushButton("xkd");
    QWidget *secondPageWidget =new QPushButton("xkd1");
    QWidget *thirdPageWidget = new QPushButton("xkd2");

    QStackedWidget *stackedWidget = new QStackedWidget(mainWindow);
    stackedWidget->addWidget(firstPageWidget);
    stackedWidget->addWidget(secondPageWidget);
    stackedWidget->addWidget(thirdPageWidget);

    QComboBox *pageComboBox = new QComboBox(mainWindow);
    pageComboBox->resize(100,40);
    pageComboBox->addItem(QObject::tr("Page 1"));
    pageComboBox->addItem(QObject::tr("Page 2"));
    pageComboBox->addItem(QObject::tr("Page 3"));
    QObject::connect(pageComboBox, SIGNAL(activated(int)),
            stackedWidget, SLOT(setCurrentIndex(int)));
    QVBoxLayout *layout = new QVBoxLayout;
//    layout->addWidget(pageComboBox);
//    layout->addWidget(stackedWidget);
//    mainWindow->setLayout(layout);
//    mainWindow->setCentralWidget(stackedWidget);
    mainWindow->show();
}

void GlodonTestGrammar::testTabBar()
{
    QWidget* widget = new QWidget();
    QTabBar* tar = new QTabBar(widget);
    widget->resize(600,400);
    tar->addTab("xingkongdao");
    tar->addTab("zhengsihua");
    tar->setGeometry(100,100,400,300);
//    tar->setTabText(1,"xingkno");

    widget->show();
}

void GlodonTestGrammar::testLayout()
{

}

void GlodonTestGrammar::testCompletor()
{
    QWidget *widget = new QWidget();
    QStringList wordList;
    wordList << "alpha" << "omega" << "omicron" << "zeta";

    QLineEdit *lineEdit = new QLineEdit(widget);
    Combobox *comboBox = new Combobox(widget);
    QCompleter *completer = new QCompleter(wordList, widget);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    lineEdit->setCompleter(completer);
    widget->resize(400,200);
    comboBox->setGeometry(100,100,100,50);
    widget->show();
}

void GlodonTestGrammar::testPushButton_Menu_ListWidget()
{
    QWidget *widget = new QWidget();
    QPushButton* btn = new QPushButton(widget);
    btn->resize(100,30);
    QMenu *menu = new QMenu(widget);
    btn->setMenu(menu);

    QListWidget *listWidget = new QListWidget(menu);
    listWidget->resize(100,200);
    for(int i = 0; i< 5; i++)
    {
        QListWidgetItem *item = new QListWidgetItem("xingkongdao");
        item->setCheckState(Qt::Checked);
        listWidget->addItem(item);
    }
    widget->resize(300,200);
    btn->move(widget->geometry().center());
    listWidget->show();
    menu->setMinimumSize(QSize(listWidget->width(), listWidget->height()));
//    QObject::connect(menu, SIGNAL(aboutToShow()), listWidget, SLOT(show()));
    widget->show();
}

void GlodonTestGrammar::testDir()
{
    QDir dir = QDir::temp();
    dir.cd("../../Roaming/Grandsoft/GBQ5/");
    // 删除掉这个目录下的所有内容
    dir.remove("RecentDirXMLFile.xml");
    dir.remove("RecentDocXMLFile.xml");
    qDebug()<<__FUNCTION__<< dir.absolutePath() << QDir::tempPath();
}

void GlodonTestGrammar::testStaticFunction()
{
    qDebug()<<__FUNCTION__;
}

void GlodonTestGrammar::testNew()
{
    /**
    这个解释应该是，p是一个int[4]类型的数组，每个元素赋值是通过buf中的元素赋值的，
    如p[0],应该是buf中前4个元素变量的二进制拼成一个int值
    指定p的创建内存地址，只能在buf开辟的内存地址上创建，相当两个变量公用一块内存区域
    */

    char buf[100] = {};
    int a[20];
    int *p = new(buf) int[4];
    int **tmp = &p;
    for(int i = 0; i<5; i++,tmp++)
        tmp[0][i] = 'a';

    for(int i = 0; i<27; i++,p++)
        qDebug()<<__FUNCTION__<<*p << sizeof(buf);
}

void GlodonTestGrammar::testTry_Catch()
{
    QWidget* widget = 0;
    int x, y ;
    x = 20;
    y = 0;
    try
    {
        widget = new QWidget();
        widget->show();
//        throw widget;
        if(y == 0)
            throw y;
        int z = x/y;
    }
    catch(...)
    {
        widget = new QWidget;
//        throw;
    }
}

void GlodonTestGrammar::testTreeWidget()
{
    QTreeWidget* treeWidget = new QTreeWidget();
    treeWidget->setColumnCount(1);
    QStringList lists;
    lists<<"name"<<"value";
    treeWidget->setHeaderLabels(lists);
//    setStyle(new QWindowsStyle()); //设置风格，windows style, mac style
//    treeWidget->setState(QAbstractItemView::ExpandingState);
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

    treeWidget->addTopLevelItem(pItemA);
    pItemA->addChild(pItemAa);
    pItemA->addChild(pItemAb);

    treeWidget->addTopLevelItem(pItemB);
    pItemB->addChild(pItemBa);

    treeWidget->addTopLevelItem(pItemC);

    pItemAa->addChild(pItemAaa);
    treeWidget->setItemsExpandable(true);

    treeWidget->show();
}

void GlodonTestGrammar::testTableView()
{

}

void GlodonTestGrammar::testProcess()
{
    QStringList lists;
    lists <<QStringLiteral("C:/Users/xingkd-a/Desktop/广东阳江2.GBQ5");
    bool value = QProcess::execute("D://V3_GJS/Trunk/ProductPlatform/GBQ/Release/Bin/GJL5.exe",
                                         lists);

    qDebug()<<__FUNCTION__<<value;
}
#include<QApplication>
void GlodonTestGrammar::testTextStream()
{

    QFile file(qApp->applicationDirPath() + "/test.txt");

    qDebug()<<__FUNCTION__<<qApp->applicationDirPath();
    qDebug()<<file.fileName();
    if( !file.open(QFile::ReadOnly ) )
    {
        qDebug()<<"error";
    }
    QTextStream ts(&file);

    qDebug()<<__FUNCTION__<<file.exists();

    QList<int> lists;
     while(!ts.atEnd())
    {
         QString str;
          str = ts.readLine();
         qDebug()<<__FUNCTION__<<str;
         str = str.simplified();
         for(int j = 0; j< str.count(); j++)
             qDebug()<<"a  = "<<str[j];

         QStringList lists  = str.split(" ");
         for(int k = 0; k < lists.count(); k++)
             qDebug()<<" b = "<< lists[k];

         static int i= 0;
         i++;
         if(i> 100)
             break;
    }
}

int add(int a, int b)
{
//    foreach(QString str, c_n2009RGs)
//        qDebug()<<str;

//    foreach(int i , c_n2222RGb)
//        qDebug()<<i;

    qDebug()<<"a + b = "<<(a+b);
    return (a+b);
}
