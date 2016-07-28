#ifndef EPQML_H
#define EPQML_H

//#include <QtDBus>
#include <QObject>
#include <QDebug>

class EPQml :public QObject
{
    Q_OBJECT
//    Q_PROPERTY(int width READ getWidth)
    Q_PROPERTY(QString message READ getMsg WRITE setMsg)
    Q_PROPERTY(QWidget* widget READ getWidget WRITE setWidget)

public:
    EPQml();

    static void qmlTranC();

    // 用C++ 代码操作qml文件
    static void interactionQml();

    // 在qml文件中调用c++对象的函数
    static void interactionC();


   /**
    qml 文件中能调用C++的对象的函数有两种：
    @a 公共槽函数
    @b Q_INVOKABLE 宏标示的函数

   */
    QString getMsg(){
        qDebug()<<Q_FUNC_INFO;
        return message;}
    void setMsg(QString msg) {
        qDebug()<<Q_FUNC_INFO;
        message = msg; }

    QWidget* getWidget();
    void setWidget(QWidget* widget);

signals:
    void testSignal(QString para1);

public slots:
    void show();
    int getValue();

public:
    int m_value;
    int width;
    QString message;
    QWidget* m_widget;
};

class EPButton : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

//signals:
//    void colorChanged();
//    void customSignal();


//public:
    EPButton(QObject* parent = 0);


};

#endif // EPQML_H
