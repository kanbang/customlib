#include "networkFactory.h"

networkAbstractFactory::networkAbstractFactory()
{
}

networkAbstractFactory::~networkAbstractFactory()
{
}
const QString& networkAbstractFactory::getAppName()
{
    return appName;
}

/*****************************************************************/
AadlgClientFactory::AadlgClientFactory() :
    networkAbstractFactory()
{
    appName = QObject::tr("AadlgClientApp");
    app = 0;
    init();
}

AadlgClientFactory::~AadlgClientFactory()
{
    if(app)
        delete app;
}

void AadlgClientFactory::init()
{
    if(!app)
        app = new AadlgClientApp();
    app->setWindowTitle(appName);
}

void AadlgClientFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/*****************************************************************/
AadlgServerFactory::AadlgServerFactory() :
    networkAbstractFactory()
{
    appName = QObject::tr("AadlgServerApp");
    app = 0;
    init();
}

AadlgServerFactory::~AadlgServerFactory()
{
    if(app)
        delete app;
}

void AadlgServerFactory::init()
{
    if(!app)
        app = new AadlgServerApp();
    app->setWindowTitle(appName);
}

void AadlgServerFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/*****************************************************************/
AbdlgUdpFactory::AbdlgUdpFactory() :
    networkAbstractFactory()
{
    appName = QObject::tr("AbdlgUdpApp");
    app = 0;
    init();
}

AbdlgUdpFactory::~AbdlgUdpFactory()
{
    if(app)
        delete app;
}

void AbdlgUdpFactory::init()
{
    if(!app)
        app = new AbdlgUdpApp();
    app->setWindowTitle(appName);
}

void AbdlgUdpFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/*****************************************************************/
AbFtpFactory::AbFtpFactory() :
    networkAbstractFactory()
{
    appName = QObject::tr("AbFtpApp");
    app = 0;
    init();
}

AbFtpFactory::~AbFtpFactory()
{
    if(app)
        delete app;
}

void AbFtpFactory::init()
{
    if(!app)
        app = new AbFtpApp();
}

void AbFtpFactory::run()
{
    // 用QCoreApplication是为了防止在编译时连接QtGui程序库。
    // QCoreApplication app(argc,argv);
    //QStringList args = QCoreApplication::arguments();
    //if (args.count() != 2) {
    //    std::cerr << "Usage: ftpget url" << std::endl
    //              << "Example:" << std::endl
    //              << "    ftpget ftp://ftp.trolltech.com/mirrors"
    //              << std::endl;
    //    return 1;
    //}

    //FtpGet getter;
    //if (!getter.getFile(QUrl(args[1])))
    //    return 1;
    //    EPFifteenFtpGet getter;
    //    if (!getter.getFile(QUrl("ftp://192.100.100.8/pub/epoffice/alpha/rhel4u5/epoffice_alpha-installer_rhel4u5-201301041234.bin")))
    //        return 1;

    //    QObject::connect(&getter, SIGNAL(done()), &app, SLOT(quit()));
    //QObject::connect(&getter, SIGNAL(done()), &app, SLOT(quit()));
    if(app){
        if(!app->getFile(QUrl("ftp://192.100.100.8/pub/epoffice/alpha/rhel5u3/"
                              "epoffice_standard-installer_rhel5u3-201312231201.bin")))
            return ;
    }
}

/*****************************************************************/
AbFtpExtendFactory::AbFtpExtendFactory() :
    networkAbstractFactory()
{
    appName = QObject::tr("AbFtpExtendApp");
    app = 0;
    init();
}

AbFtpExtendFactory::~AbFtpExtendFactory()
{
    if(app)
        delete app;
}

void AbFtpExtendFactory::init()
{
    if(!app)
        app = new AbFtpExtendApp();
}

void AbFtpExtendFactory::run()
{
    QStringList args = QCoreApplication::arguments();

    if (args.count() != 2) {
        std::cerr << "Usage: spider url" << std::endl
                  << "Example:" << std::endl
                  << "    spider ftp://ftp.trolltech.com/freebies/"
                  << "leafnode" << std::endl;
        return ;
    }

    //Spider spider;
    //if (!spider.getDirectory(QUrl(args[1])))
    //    return 1;

    //QObject::connect(&spider, SIGNAL(done()), &app, SLOT(quit()));
    if(app){
        if(!app->getDirectory(QUrl(args[1])))
            return ;
    }
}

/*****************************************************************/
AbHttpFactory::AbHttpFactory() :
    networkAbstractFactory()
{
    appName = QObject::tr("AbHttpApp");
    app = 0;
    init();
}

AbHttpFactory::~AbHttpFactory()
{
    if(app)
        delete app;
}

void AbHttpFactory::init()
{
    if(!app)
        app = new AbHttpApp();
}

void AbHttpFactory::run()
{
    QStringList args = QCoreApplication::arguments();

    if (args.count() != 2) {
        std::cerr << "Usage: spider url" << std::endl
                  << "Example:" << std::endl
                  << "    spider ftp://ftp.trolltech.com/freebies/"
                  << "leafnode" << std::endl;
        return ;
    }

    //Spider spider;
    //if (!spider.getDirectory(QUrl(args[1])))
    //    return 1;

    if(app){
        if(!app->getFile(QUrl(args[1])))
            return ;
    }
}

/*****************************************************************/
AbUdpWidgetFactory::AbUdpWidgetFactory() :
    networkAbstractFactory()
{
    appName = QObject::tr("AbUdpWidgetApp");
    app = 0;
    init();
}

AbUdpWidgetFactory::~AbUdpWidgetFactory()
{
    if(app)
        delete app;
}

void AbUdpWidgetFactory::init()
{
    if(!app)
        app = new AbUdpWidgetApp();
    app->setWindowTitle(appName);
}

void AbUdpWidgetFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/*****************************************************************/
AClientWidgetFactory::AClientWidgetFactory() :
    networkAbstractFactory()
{
    appName = QObject::tr("AClientWidgetApp");
    app = 0;
    init();
}

AClientWidgetFactory::~AClientWidgetFactory()
{
    if(app)
        delete app;
}

void AClientWidgetFactory::init()
{
    if(!app)
        app = new AClientWidgetApp();
    app->setWindowTitle(appName);
}

void AClientWidgetFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/*****************************************************************/
AcTcpServerWindowFactory::AcTcpServerWindowFactory() :
    networkAbstractFactory()
{
    appName = QObject::tr("AcTcpServerWindowApp");
    app = 0;
    init();
}

AcTcpServerWindowFactory::~AcTcpServerWindowFactory()
{
    if(app)
        delete app;
}

void AcTcpServerWindowFactory::init()
{
    if(!app)
        app = new AcTcpServerWindowApp();
    app->setWindowTitle(appName);
}

void AcTcpServerWindowFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

/*****************************************************************/
AServerWidgetFactory::AServerWidgetFactory() :
    networkAbstractFactory()
{
    appName = QObject::tr("AServerWidgetApp");
    app = 0;
    init();
}

AServerWidgetFactory::~AServerWidgetFactory()
{
    if(app)
        delete app;
}

void AServerWidgetFactory::init()
{
    if(!app)
        app = new AServerWidgetApp();
    app->setWindowTitle(appName);
}

void AServerWidgetFactory::run()
{
    if(app){
        if(app->isVisible())
            app->hide();
        else
            app->show();
    }
}

//******************************代理工厂类******************************/
networkFactoryProxy* networkFactoryProxy::instance = 0;
networkFactoryProxy::networkFactoryProxy()
{
    m_apps.append(new AadlgClientFactory());
    m_apps.append(new AadlgServerFactory());
    m_apps.append(new AbdlgUdpFactory());
    m_apps.append(new AbFtpFactory());
    m_apps.append(new AbFtpExtendFactory());
    m_apps.append(new AbHttpFactory());
    m_apps.append(new AbUdpWidgetFactory());
    m_apps.append(new AClientWidgetFactory());
    m_apps.append(new AcTcpServerWindowFactory());
    m_apps.append(new AServerWidgetFactory());

    updateAppNameList();
}

bool networkFactoryProxy::registerFactory(networkAbstractFactory *factory)
{
    if(contains(factory))
        return false;
    m_apps.append(factory);
    updateAppNameList();
    return true;
}

bool networkFactoryProxy::contains(networkAbstractFactory *factory)
{
    foreach(networkAbstractFactory* item, m_apps)
        if(item->getAppName() == factory->getAppName())
            return true;
    return false;
}

const QStringList& networkFactoryProxy::getAppNameList()
{
    return applist;
}

networkAbstractFactory* networkFactoryProxy::getFactory(const QString &appname)
{
    foreach(networkAbstractFactory* item, m_apps)
        if(item->getAppName() == appname)
            return item;
    return 0;
}

networkFactoryProxy* networkFactoryProxy::getInstance()
{
    if(!instance)
        instance = new networkFactoryProxy;

    return instance;
}

void networkFactoryProxy::updateAppNameList()
{
    applist.clear();
    foreach(networkAbstractFactory* item, m_apps)
        applist.append(item->getAppName());
}
