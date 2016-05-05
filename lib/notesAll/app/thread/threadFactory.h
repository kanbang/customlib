#ifndef THREADFACTORY_H
#define THREADFACTORY_H
#include <ETAllHeader.h>

// 为什么要声明这两句才能编译过去？
class ShareMemoryLoad;
class ShareMemoryShow;
class AdImageWindowApp;
class AcThreadWindowApp;

class threadAbstractFactory
{
public:
    virtual void run() = 0;
    virtual ~threadAbstractFactory();
    const QString& getAppName();

protected:
    threadAbstractFactory();
    QString appName;
};

/*********************************************************/
class AadlgThreadFactory : public threadAbstractFactory
{
public:
    AadlgThreadFactory();
    ~AadlgThreadFactory();

    virtual void run();
private:
    void init();
    AadlgThreadApp* app;
};

/*********************************************************/
class AbShareMemoryLoadFactory : public threadAbstractFactory
{
public:
    AbShareMemoryLoadFactory();
    ~AbShareMemoryLoadFactory();

    virtual void run();
private:
    void init();
    ShareMemoryLoad* app;
};

class AbShareMemoryShowFactory : public threadAbstractFactory
{
public:
    AbShareMemoryShowFactory();
    ~AbShareMemoryShowFactory();

    virtual void run();
private:
    void init();
    ShareMemoryShow* app;
};

/*********************************************************/
class AcThreadWindowFactory : public threadAbstractFactory
{
public:
    AcThreadWindowFactory();
    ~AcThreadWindowFactory();

    virtual void run();
private:
    void init();
    AcThreadWindowApp* app;
};

/*********************************************************/
class AdImageWindowFactory : public threadAbstractFactory
{
public:
    AdImageWindowFactory();
    ~AdImageWindowFactory();

    virtual void run();
private:
    void init();
    AdImageWindowApp* app;
};

/**********************************************************/
class threadFactoryProxy
{
public:
    bool registerFactory(threadAbstractFactory* factory);
    bool contains(threadAbstractFactory* factory);
    const QStringList& getAppNameList();
    threadAbstractFactory* getFactory(const QString& appname);
    static threadFactoryProxy* getInstance();

private:
    threadFactoryProxy();
    void updateNameList();
    static threadFactoryProxy* instance;
    QList<threadAbstractFactory*> m_apps;
    QStringList applist;
};

#endif // THREADFACTORY_H
