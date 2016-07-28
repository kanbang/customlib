#include "threadFactory.h"

threadAbstractFactory::threadAbstractFactory()
{
}

threadAbstractFactory::~threadAbstractFactory()
{

}

const QString& threadAbstractFactory::getAppName()
{
    return appName;
}

/*******************************************************************/
AadlgThreadFactory::AadlgThreadFactory() :
    threadAbstractFactory()
{
    appName = QObject::tr("AadlgThreadApp");
    app = 0;
    init();
}

AadlgThreadFactory::~AadlgThreadFactory()
{
    if(app)
        delete app;
}

void AadlgThreadFactory::init()
{
    if(!app)
        app = new AadlgThreadApp();
    app->setWindowTitle(appName);
}

void AadlgThreadFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/*******************************************************************/
AbShareMemoryLoadFactory::AbShareMemoryLoadFactory() :
    threadAbstractFactory()
{
    appName = QObject::tr("ShareMemoryLoad");
    app = 0;
    init();
}

AbShareMemoryLoadFactory::~AbShareMemoryLoadFactory()
{
    if(app)
        delete app;
}

void AbShareMemoryLoadFactory::init()
{
    if(!app)
        app = new ShareMemoryLoad();
    app->setWindowTitle(appName);
}

void AbShareMemoryLoadFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/////////////////////////////////////
AbShareMemoryShowFactory::AbShareMemoryShowFactory() :
    threadAbstractFactory()
{
    appName = QObject::tr("ShareMemoryShow");
    app = 0;
    init();
}

AbShareMemoryShowFactory::~AbShareMemoryShowFactory()
{
    if(app)
        delete app;
}

void AbShareMemoryShowFactory::init()
{
    if(!app)
        app = new ShareMemoryShow();
    app->setWindowTitle(appName);
}

void AbShareMemoryShowFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/*******************************************************************/
AcThreadWindowFactory::AcThreadWindowFactory() :
    threadAbstractFactory()
{
    appName = QObject::tr("AcThreadWindowApp");
    app = 0;
    init();
}

AcThreadWindowFactory::~AcThreadWindowFactory()
{
    if(app)
        delete app;
}

void AcThreadWindowFactory::init()
{
    if(!app)
        app = new AcThreadWindowApp();
    app->setWindowTitle(appName);
}

void AcThreadWindowFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/*******************************************************************/
AdImageWindowFactory::AdImageWindowFactory() :
    threadAbstractFactory()
{
    appName = QObject::tr("AdImageWindowApp");
    app = 0;
    init();
}

AdImageWindowFactory::~AdImageWindowFactory()
{
    if(app)
        delete app;
}

void AdImageWindowFactory::init()
{
    if(!app)
        app = new AdImageWindowApp();
    app->setWindowTitle(appName);
}

void AdImageWindowFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/**********************************代理工厂类*******************************/
bool threadFactoryProxy::registerFactory(threadAbstractFactory *factory)
{
    if(contains(factory))
        return false;
    m_apps.append(factory);
    updateNameList();
    return true;
}

threadFactoryProxy* threadFactoryProxy::instance = 0;
threadFactoryProxy::threadFactoryProxy()
{
    m_apps.clear();
    m_apps.append(new AadlgThreadFactory());
    m_apps.append(new AbShareMemoryLoadFactory());
    m_apps.append(new AbShareMemoryShowFactory());
    m_apps.append(new AcThreadWindowFactory());
    m_apps.append(new AdImageWindowFactory());

    updateNameList();
}

bool threadFactoryProxy::contains(threadAbstractFactory *factory)
{
    foreach(threadAbstractFactory* item, m_apps)
        if(item->getAppName() == factory->getAppName())
            return true;
    return false;
}

void threadFactoryProxy::updateNameList()
{
    applist.clear();
    foreach(threadAbstractFactory* factory, m_apps)
        applist.append(factory->getAppName());
}

const QStringList& threadFactoryProxy::getAppNameList()
{
    return applist;
}

threadFactoryProxy* threadFactoryProxy::getInstance()
{
    if(!instance)
        instance = new threadFactoryProxy();

    return instance;
}

threadAbstractFactory* threadFactoryProxy::getFactory(const QString &appname)
{
    foreach(threadAbstractFactory* factory, m_apps)
        if(factory->getAppName() == appname)
            return factory;
    return 0;
}
