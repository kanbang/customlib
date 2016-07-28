#ifndef NETWORKFACTORY_H
#define NETWORKFACTORY_H
#include <QList>
#include <QString>
#include <ENAllHeader.h>
//添加 #include<QString> 就好了。

/**
类或结构体的前向声明只能用来定义指针对象，因为编译到这里时还没有发现定义，不知道该类或者结构的内部成员，
没有办法具体的构造一个对象，所以会报错。将类成员改成指针就好了。

 */
class networkAbstractFactory
{
public:
    virtual void run() = 0;
    virtual ~networkAbstractFactory();
    const QString& getAppName();

protected:
    networkAbstractFactory();
    QString appName;
};
/**********************************************************/

class AadlgClientFactory : public networkAbstractFactory
{
public:
    AadlgClientFactory();
    ~AadlgClientFactory();

    virtual void run();

private:
    void init();
    AadlgClientApp *app;
};
/**********************************************************/

class AadlgServerFactory : public networkAbstractFactory
{
public:
    AadlgServerFactory();
    ~AadlgServerFactory();

    virtual void run();
private:
    void init();
    AadlgServerApp* app;
};
/**********************************************************/

class AbdlgUdpFactory : public networkAbstractFactory
{
public:
    AbdlgUdpFactory();
    ~AbdlgUdpFactory();

    virtual void run();
private:
    void init();
    AbdlgUdpApp* app;
};
/**********************************************************/

class AbFtpFactory : public networkAbstractFactory
{
public:
    AbFtpFactory();
    ~AbFtpFactory();

    virtual void run();

private:
    void init();
};
/**********************************************************/

class AbFtpExtendFactory : public networkAbstractFactory
{
public:
    AbFtpExtendFactory();
    ~AbFtpExtendFactory();

    virtual void run();

private:
    void init();
    AbFtpExtendApp* app;
};
/**********************************************************/

class AbHttpFactory : public networkAbstractFactory
{
public:
    AbHttpFactory();
    ~AbHttpFactory();

    virtual void run();

private:
    void init();
    AbHttpApp* app;
};
/**********************************************************/

class AbUdpWidgetFactory : public networkAbstractFactory
{
public:
    AbUdpWidgetFactory();
    ~AbUdpWidgetFactory();

    virtual void run();
private:
    void init();
    AbUdpWidgetApp* app;
};
/**********************************************************/

class AClientWidgetFactory : public networkAbstractFactory
{
public:
    AClientWidgetFactory();
    ~AClientWidgetFactory();

    virtual void run();
private:
    void init();
    AClientWidgetApp* app;
};
/**********************************************************/

class AcTcpServerWindowFactory : public networkAbstractFactory
{
public:
    AcTcpServerWindowFactory();
    ~AcTcpServerWindowFactory();

    virtual void run();
private:
    void init();
    AcTcpServerWindowApp* app;
};
/**********************************************************/

class AServerWidgetFactory : public networkAbstractFactory
{
public:
    AServerWidgetFactory();
    ~AServerWidgetFactory();

    virtual void run();
private:
    void init();
    AServerWidgetApp* app;
};
/**********************************************************/

class networkFactoryProxy
{
public:
    bool registerFactory(networkAbstractFactory *factory);
    bool contains(networkAbstractFactory* factory);
    const QStringList& getAppNameList();
    networkAbstractFactory* getFactory(const QString& appname);
    static networkFactoryProxy* getInstance();

private:
    networkFactoryProxy();
    void updateAppNameList();
    static networkFactoryProxy* instance;
    QList<networkAbstractFactory*> m_apps;
    QStringList applist;
};


#endif // NETWORKFACTORY_H
