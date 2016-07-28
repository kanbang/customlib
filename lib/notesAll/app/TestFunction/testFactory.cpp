#include "testFactory.h"

testAbstractFactory::testAbstractFactory()
{
}

testAbstractFactory::~testAbstractFactory()
{
}

const QString& testAbstractFactory::getAppName()
{
    return appName;
}

/*********************/
AbImageMoveTransparentFactory::AbImageMoveTransparentFactory() :
    testAbstractFactory()
{
    appName = QObject::tr("AbImageMoveTransparent");
    app = 0;
    init();
}

AbImageMoveTransparentFactory::~AbImageMoveTransparentFactory()
{
    if(app)
        delete app;
}

void AbImageMoveTransparentFactory::init()
{
    if(!app)
        app = new AbImageMoveTransparent();
    app->setWindowTitle(appName);
}

void AbImageMoveTransparentFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/*********************/
AaImagePixelColorFactory::AaImagePixelColorFactory() :
    testAbstractFactory()
{
    appName = QObject::tr("AaImagePixelColor");
    app = 0;
    init();
}

AaImagePixelColorFactory::~AaImagePixelColorFactory()
{
    if(app)
        delete app;
}

void AaImagePixelColorFactory::init()
{
    if(!app)
        app = new AaImagePixelColor();
    app->setWindowTitle(appName);
}

void AaImagePixelColorFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/*********************/
AcMouseAutoClickWindowFactory::AcMouseAutoClickWindowFactory() :
    testAbstractFactory()
{
    appName = QObject::tr("AcMouseAutoClickWindow");
    app = 0;
    init();
}

AcMouseAutoClickWindowFactory::~AcMouseAutoClickWindowFactory()
{
    if(app)
        delete app;
}

void AcMouseAutoClickWindowFactory::init()
{
    if(!app)
        app = new AcMouseAutoClickWindow();
    app->setWindowTitle(appName);
}

void AcMouseAutoClickWindowFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/*********************/
AdScrollAreaViewFactory::AdScrollAreaViewFactory() :
    testAbstractFactory()
{
    appName = QObject::tr("AdScrollAreaView");
    app = 0;
    init();
}

AdScrollAreaViewFactory::~AdScrollAreaViewFactory()
{
    if(app)
        delete app;
}

void AdScrollAreaViewFactory::init()
{
    if(!app)
        app = new AdScrollAreaView();
    app->setRect(QRect(0,0,400,600));
    app->viewport()->resize(400,600);
    app->setWindowTitle(appName);
}

void AdScrollAreaViewFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/*********************代理工厂类****************************/
bool testFactoryProxy::registerFactory(testAbstractFactory *factory)
{
    if(contains(factory))
        return false;

    m_apps.append(factory);
    updateAppNameList();
    return true;
}

bool testFactoryProxy::contains(testAbstractFactory *factory)
{
    foreach(testAbstractFactory *item,m_apps)
        if(item->getAppName() == factory->getAppName())
            return true;
    return false;
}

const QStringList& testFactoryProxy::getAppNameList()
{
    return applist;
}

testAbstractFactory* testFactoryProxy::getFactory(const QString &appname)
{
    foreach(testAbstractFactory* factory, m_apps)
        if(factory->getAppName() == appname)
            return factory;
    return 0;
}

testFactoryProxy* testFactoryProxy::getInstance()
{
    if(!instance)
        instance = new testFactoryProxy();
    return instance;
}

testFactoryProxy::testFactoryProxy()
{
    m_apps.clear();
    m_apps.append(new AbImageMoveTransparentFactory());
    m_apps.append(new AaImagePixelColorFactory());
    m_apps.append(new AcMouseAutoClickWindowFactory());
    m_apps.append(new AdScrollAreaViewFactory());

    updateAppNameList();
}

void testFactoryProxy::updateAppNameList()
{
    applist.clear();
    foreach(testAbstractFactory* factory , m_apps)
        applist.append(factory->getAppName());
}

testFactoryProxy* testFactoryProxy::instance = 0;
