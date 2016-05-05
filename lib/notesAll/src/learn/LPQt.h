#ifndef LPQT_H
#define LPQT_H

class LPQt
{
public:
    LPQt();  //forever
    void    signalSlot();
    void    libraryAndProSettings(); //这个非常重要
    void    aboutProFile();
    void    aboutProFile(bool moreDetail);
    void    aboutqmake();
    void    xmlTagName();

    /**
     \brief     这是重点   运行报错
     */
    void    errorInRun();
    void    staticCompile();
    void    aboutWidgetEvent();
    void    designerUi();
    void    relationWidgetAndLayout();

    /**
     \brief     获取widget上面的图片。
    */
    void    aboutQPixmapGrabWidget();
    /**
     \brief     关于QPainter类的使用。
     */
    void    aboutQPainter();
    /**
     \brief     关于窗口坐标，已经部件在窗口中的设定。
     */
    void    aboutWidgetCoordinate();
    /**
     \brief     关于widget的内存管理，主要是在父窗口关闭了后，子窗口是否关闭
     */
    void    aboutParentWidgetPointManager();

    /**
     \brief     编译出错。
     */
    void    aboutCompile();
    void    programToExe();
    /**
     \brief     运行程序生成lib(库)的时候，要指定哪个程序来调用。
    */
    void    runWithLib();
    /**
     \brief     函数输出
     */
    void    output();
    /**
     \brief     使用cin
     */
    void    input();

    /**
     \brief     在别的文件这使用另一个文件中的变量。
    */
    void    useVariableInOtherFile();
    /**
     \brief     多进程
    */
    void    thread();
    /**
     \brief     关于QPainter要一定在paintEvent函数里面调用的修改。
    */
    void    paintInPaintEvent();

    void    ScrollBarVisibleEnabled();
    /**
     \brief     关于图形包含鼠标坐标的判断
    */
    void    pixmapContainsCursor();
    /**
     \brief     关于内存开辟的问题
    */
    void    newDelete();
    /**
     \brief     关于Qt编码的问题
    */
    void    aboutCodes();
    /**
     \brief     显示中文的问题
    */
    void    showChinese();
    /**
     \brief     设置背景
    */
    void    background();
    /**
     @brief 关于debug调式的时候没有显示出QString和QList的问题
     */
    void    aboutDebug();
    /**
     \brief 关于赋值出现问题的原因
     */
    void    assignmentReason();
    /**
     \brief 实现工具栏上添加可以双进的菜单的功能
     */
    void    aboutToolBarDoubleClick();
    //environment class
    // QClipboard,QDesktopWidget,QEvent,QFontDatabase,QMimeSourceFactory, QPixmapCache,
    // QSessionManager,QTranslatorMessage.
    /**
     Qt-4.8.5 编译没有dbus模块，是因为ubuntu里面没有dbus相关的模块
     需要安装qt编译的时候需要的dbus库
     dbus-1.9.4.tar.gz,如果编译需要 expat，则下载expat，然后在configure， make， make install
     */
    void aboutDBus();

    void aboutDataTypeTrans();

    void Q_DECL_EXPORT();
};

#endif // LPQT_H
