#include <QGuiApplication>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView *m_view = new QQuickView();
    m_view->setSource(QUrl("main.qml"));

    return app.exec();
}
