#include "EPQml.h"
#include <QDeclarativeView>
#include <QtDeclarative>
#include <QDebug>

const QString FILEPATH = "/home/xkd/KuaiPan/learn/program/notesAll/src/syberos/EPQmlInteractionC.qml";
EPQml::EPQml()
{
    m_value = 10;
    message = "xingkd";
    m_widget = new QWidget();
}

void EPQml::qmlTranC()
{
    QDeclarativeView *view = new QDeclarativeView();
    QDeclarativeEngine engine;
    QDeclarativeContext *windowContext = new QDeclarativeContext(engine.rootContext());
    QDeclarativeContext *context = view->rootContext();
    context->setContextProperty("backgroundColor", QColor(Qt::red));
    view->setSource(QUrl::fromLocalFile(FILEPATH));

    view->show();
    //    view.rootContext()->setContextProperty("palette", new CustomPalette);
}

// 用C++ 代码操作qml文件
void EPQml::interactionQml()
{
    //    QDeclarativeEngine *engine = new QDeclarativeEngine(this);
    //    QDeclarativeComponent component(engine, QUrl::fromLocalFile("main.qml"));
    //    QObject *obj = component.create();


        QDeclarativeEngine engine;
    //    QDeclarativeContext *windowContext = new QDeclarativeContext(engine.rootContext());
    //    windowContext->setContextProperty("backgroundColor", QColor(Qt::yellow));

        QDeclarativeComponent component(&engine, "main.qml");
    //    QObject *window = component.create(windowContext);

        QDeclarativeItem *item = qobject_cast<QDeclarativeItem *>(component.create());

        for(int i = 0; i< item->children().count(); i++)
        {
            qDebug()<<__FUNCTION__<<item->childItems().at(i)->boundingRect();
            item->childItems().at(i)->setRotation(23);
            item->setProperty("width", 400);
        }

        QDeclarativeView *view = new QDeclarativeView();

        // 这个解析的是 .build/bin/main.qml 的文件
        // 可以用 QDir::currentPath() 查看当前路径

        view->setSource(QUrl("main.qml"));

        QGraphicsObject* object = view->rootObject();
        object->setProperty("width", 400);
        QObject* rect = object->findChild<QObject*>("rect");
        if(rect)
        {
            rect->setProperty("color", "red");
            QObject *obj = rect->findChild<QObject*>("Hello");
            if(obj)
            {
                obj->setProperty("color", "white");
            }
        }
        view->show();

    //    qDebug()<<__FUNCTION__<<item->children().count() << item->boundingRect();
}

void EPQml::interactionC()
{
    // 这里qml这个对象没有父类,那么就会被QML析构了.
    EPQml *qml = new EPQml();
    QDeclarativeView *view = new QDeclarativeView();

    QDeclarativeContext *context = view->rootContext();

    // 要先注册，然后再加载qml文件，否则会不认识。 EPQml 1.0
    // 目的是可以在qml文件中定义  EPQml {id: qml; ... }
    qmlRegisterType<EPQml>("EPQml",1,0,"EPQml");

    // 先注册实现，然后在加载qml文件，这样qml文件才可以认识_qml
    context->setContextProperty("_qml", qml);
    view->setSource(QUrl(FILEPATH));
//    qmlRegisterType<EPQml>();
    view->show();
    //    context->setContextProperty();
}

QWidget *EPQml::getWidget()
{
//    QWidget* widget = new QWidget();

    qDebug()<<__PRETTY_FUNCTION__<<m_widget;
//    widget->setWindowTitle("xingkongdao");
    return m_widget;
}

void EPQml::setWidget(QWidget *widget)
{

}

void EPQml::show()
{
    m_value = 12;
    emit testSignal(QString("xingkongdao"));
    qDebug()<<__PRETTY_FUNCTION__<<m_value;
}

int EPQml::getValue()
{
    return m_value;
}
