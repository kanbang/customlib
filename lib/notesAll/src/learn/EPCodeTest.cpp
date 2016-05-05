#include "EPCodeTest.h"
#include <QtGui>

EPCodeTest::EPCodeTest()
{
    /**
    QTextStream cin(stdin, QIODevice::ReadOnly);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    QTextStream cerr(stderr, QIODevice::WriteOnly);
    QDialog *d = new QDialog;
    QLabel *label = new QLabel(d);
    label->setAutoFillBackground(true);
    label->setAttribute(Qt::WA_SetPalette);
    QPalette palette = label->palette();
    palette.setBrush(label->backgroundRole(),QBrush(Qt::red));
    label->setPalette(palette);
    label->setStyleSheet("QLabel{color : white;}");
    label->setText("xkd");
    label->resize(100,40);
    label->show();
    d->show();

    QTableWidget *tw = new QTableWidget;
    tw->setAutoFillBackground(false);
    tw->setRowCount(1);
    tw->setColumnCount(1);
    Delegate *dg = new Delegate;
    tw->setItemDelegate(dg);
    tw->setCellWidget(0,0,label);
    tw->show();

    int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    int *p = arr[0];
    for(int i = 0;i<3;i++,p=p+4)
        for(int j = 0;j<4;j++)
        {
            qDebug()<<*(p+j);
        }

    int *p1 = new int[3];
    for(int i = 0; i<3; i++)
    {
       p1[i]= i;
    }

    int *pp = p1;
    for(int i = 0;i<3;i++,p1++)
    {
        qDebug()<<*p1;
    }

    p1 = pp;
    for(int i = 0;i<3;i++,p1++)
    {
        qDebug()<<*p1;
    }

    QString str ="  SP";
    qDebug()<<str.replace(" ","");

     */
}

void EPCodeTest::transform()
{
    /**
      \note
        QMatrix scale;
        scale.scale(2,-2);

        QPoint pt(100,100);
        scale.map(pt);    (200,-200);


        QPixmap pixmap(":/Ades.png");这个文件必须要添加到资源文件中
        qDebug()<<"pixmap "<<pixmap.save("/home/xkd/xx.png");
        QMatrix scale;
        scale.scale(1,-1);

        pixmap = pixmap.transformed(scale);
        qDebug()<<pixmap.save("/home/xkd/xkd.png");

      */
}

void EPCodeTest::aboutList()
{
    /**
      \brief    在一个列表中，如果想使用unique函数，则要先使用sort();

      list<int> lists;     1 2 3 2 1
      lists.sort();        1 1 2 2 3
      lists.unique();      1 2 3

      */
}

void EPCodeTest::aboutFontWidth()
{
    /**

    QListWidget *wg = new QListWidget;
    wg->addItem("xkd");

    wg->show();

    QString str ="xkd";
    int i = 0;
    QList<int> list;
    QList<QString> lists;
    for(int i = 0; i<10;i++){
        list.append(i);
        lists.append("xkd");
    }
    qDebug()<<str.isEmpty();

    QFont font("Times", 10, QFont::Bold);
    QFontMetricsF fmt(font);
    QString str = "Xingkongdaoxingkongdao";
    float width = fmt.width(str);
    float step = width/str.count();
    qDebug()<<width << "  "<< step;
    int realWidth = 40;
    int rest = 5%3;
    int contains = realWidth/step;
    int row = width/realWidth;
    QString temp;
    QStringList lists;
    for(int i = 0; i<str.count();i++)
    {
        temp.append(str[i]);
        QString s;
        if(i < str.count()-1)
            s.append(str[i+1]);
        if(fmt.width(temp) < realWidth && fmt.width(temp+s) > realWidth)
        {
            lists.append(temp);
            temp.clear();
        }else
        {
            if(i == str.count()-1)
            {
                lists.append(temp);
            }
        }
    }
    qDebug()<<lists;
    foreach(QString str, lists)
    {
        qDebug()<<"width "<<fmt.width(str);
    }

    QPushButton *btn = new QPushButton;
    btn->resize(80,40);
    QTextCodec *codec = QTextCodec::codecForName("GB18030");
    QString str = codec->toUnicode("淡淡的");
    btn->setText(QObject::tr("淡淡的"));
    btn->show();
     */
}

pointerClass* EPloadPointer(int *num)
{
    *num = 10;
    pointerClass *p = new pointerClass[*num];
    pointerClass *temp = p;
    for(int i = 0; i<10; i++, p++)
    {
        p->setVal(i);
    }
    return temp;
}
