#include "LPqtClassFunction.h"

LPqtClassFunction::LPqtClassFunction()
{
}

void LPqtClassFunction::mutex()
{
    /***********************
      @ 在QThread类中
        sleep(int sec) 当程序运行到这里时停顿sec秒。
        wait(); main()函数结束会终结整个程序，它会杀掉所有其他线程。

      @ QMutex类
        lock();
        unlock();

        ****************/
}

void LPqtClassFunction::object()
{
    /*************************
      @ QList<T> QObject::findChildren ( const QString & name = QString() ) const

        主窗体是QMainWdow，中央挂件是QTabWidget，而每一个QTabWidget子窗口中又有QTextEdit，
        这样得组合就是经典得多标签页文本编辑器样式，当然这个暑假我也在做这种编辑器。
        通常我们可以很容易得获得QMainWindow上QTabWidget控件得对象，
        但是想要直接操作QTabWidget中嵌套得QTextEdit就不能直接引用，现在我们有了这个函数就可以轻松搞定了，函数原型如下：
        QList<T> QObject::findChildren(const QString &<EM>name</EM>=QString()) const
        当然关于“找孩子”得函数不只这一个，具体得大家可以再查文档，这里给出一个例子：
        QList<QLineEdit *> lineEdit = tabWidget.findChildren<QLineEdit *>();
        这句话的意思就是在tabWidget 挂件种寻找所有得QLineEdit控件，
        然后返回给QList容器（QList容器中每一个元素都为 QLineEdit * 类型）

        QList<QLineEdit *> lineEdit = tabWidget.findChildren<QLineEdit *>("lineEdit");
        找到objectName为lineEidt的对象。

      ********************/
}

void LPqtClassFunction::painterPath()
{
    /********************************
      @ QPainterPath是一个绘图路径。它设置好图形的轮廓。
        QPainter::drawPath(QPainterPath path)这个函数把QPainterPath设置好的路径画出来。

      *************************/
}

void LPqtClassFunction::painter()
{
    /***********
      @ painter.save();  //先把painter的状态保存。
        painter.setWorldMatrix(affine);
        painter.rotate(10); //设置坐标转换
        painter.setPen(Qt::red); //设置painter的画笔
        painter.drawLine(QPoint(0,0),QPoint(50,50)); //画了一条(0,0),(100,100)的红色直线
        painter.restore();  //恢复刚开始保存的状态(。
        painter.drawLine(QPoint(0,0),QPoint(50,50)); // 画了一条(0,0),(50,50)的默认颜色的直线。

      @ 在Image上面画图，当下次再画的时候，原来画的图还在（dirty),用image.fill(0).填充掉，就可以重新画了。
        当新建一个QImage对象的时候，当把图画到窗口上后出现背景乱填充的时候，要先用fill(0), 0值是透明。

      @ double m22 = m_Image.rect().height()/(数据的长度);
        double m11 = m_Image.rect().width()/(数据的长度);
        m_Affine = QMatrix(m11,0,0,m22,200(点200是原点),-1000*m22(y轴坐标从那个点(1000)开始);

      @ 如果在一个窗口中有很多的子窗口绘图，那么可以在主窗口中调用QPainter painter(子窗口的指针),这样还不可以绘图，
        还要设置主窗口的属性 setAttribute(Qt::WA_PaintOutsidePaintEvent);这样就可以画图了。

      @ painter.setClipRect(QRect(0,0,150,150));只有QRect这个区域内可见
      *********/
}

void LPqtClassFunction::widget()
{
    /**********
      @ setMask(const QRegion &region);
        设置一个除了该区域之外的地方透明。
      @ 当试图关闭一个窗口，它首先向该窗口发送QCloseEvent事件，窗口响应这个事件，
        并且隐藏窗口，默认的隐藏操作由QWidget::closeEvent()执行。如果该窗口设置了Qt::WA_DeleteOnClose标志，
        还将会删除这个窗口。在没有设置该标记的情况下，窗口仅仅是隐藏而没有被删除，只有在该窗口是最后一个可视的窗口时，
        关闭该窗口还会发送QApplication::lastWindowClosed()信号，默认情况下会退出程序。
      @ 当构造函数为QMyDialog(QWidget* parent){ this->setParent(parent); }发现对话框为嵌入在父窗口内部，而不是独立的窗口。
        当构造函数为QMyDialog(QWidget* parent) : QDialog(parent)，即调用其父类的构造函数，对话框才与窗口建立了正常的父子关系。

      @ 创建窗口（QWidget）的时候出现的错误，修改方法
        执行时出现QWidget: Cannot create a QWidget when no GUI is being used
        是因为QCoreApplication的问题，把它改成QApplication就OK了。

      *******/
}

void LPqtClassFunction::dir()
{
    /***********************
      @ QDir(.).mkpath("xkd"); //在当前路径下创建xkd这个文件夹
      ***************/
}

void LPqtClassFunction::undoCommand()
{
    /*************************
     如果是多窗口则需要用QUndoGroup
     每个窗口用一个QUndoStack
     每个命令用一个QUndoCommand
     自己实现QUndoCommand的子类，并且重新实现redo和undo函数即可

    ***************/
}

void LPqtClassFunction::settings()
{
    /***********
     QSettings 类是用来读取整个系统的置配信息数据非常的好用
     QSettings 其实也是生成一个文件，然后把信息写入这个文件，下次再把信息读出来。
     例如：
     QSettings ss("/home/xkd/ini",QSettings::IniFormat);
     ss.setValue("xkd","xxxx");
     那么在ini这个文件的显示的内容是：
     ［General]
      xkd=xxxx
     *********/
}
/************
  * model/view
  ***********/
void LPqtClassFunction::modelView()
{
    /*************
     @ model
     ***/
}

/****************************
  * QtSql
  **************************/
void LPqtClassFunction::qsql()
{
    /*********

      ****/
}

#include <QPainter>

Delegate::Delegate(QObject *parent) :QItemDelegate(parent)
{

}

void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->fillRect(option.rect,QBrush(Qt::red));

    QItemDelegate::paint(painter,option,index);
}
