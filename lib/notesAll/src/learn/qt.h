#ifndef QT_H
#define QT_H

/**
    Qt framework 的修改与维护
    Qt 中间件的开发与维护
    Qt 裁剪与移植
    嵌入式linux 开发

    对于一个信号对应一个反应槽的连接来说，一秒钟可以调用两百万次；
    对于一个信号对应两个反应槽的连接来说，一秒钟可以调用一百二十万次。
*/
class qt
{
public:
    qt();

    void memcpyTest();
    void qwidget_setWindowFlags();
    void qwidget_keyPressEvent(/*QKeyEvent *event*/);
    void qtimer();
    void signalslot();
    void cast();
};
#endif // QT_H
