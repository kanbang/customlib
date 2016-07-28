#ifndef TESTFACTORY_H
#define TESTFACTORY_H
#include <QString>
#include <ETestHeader.h>

class AbImageMoveTransparent;
class AaImagePixelColor;
class AcMouseAutoClickWindow;
class AdScrollAreaView;

class testAbstractFactory
{
public:
    virtual void run() = 0;
    virtual ~testAbstractFactory();
    const QString& getAppName();

protected:
    testAbstractFactory();
    QString appName;
};
/*******************************************************/

class AbImageMoveTransparentFactory : public testAbstractFactory
{
public:
    AbImageMoveTransparentFactory();
    ~AbImageMoveTransparentFactory();

    virtual void run();

private:
    void init();
    AbImageMoveTransparent* app;
};
/**************************************************************/

class AaImagePixelColorFactory : public testAbstractFactory
{
public:
    AaImagePixelColorFactory();
    ~AaImagePixelColorFactory();

    virtual void run();

private:
    void init();
    AaImagePixelColor* app;
};
/**************************************************************/

class AcMouseAutoClickWindowFactory : public testAbstractFactory
{
public:
    AcMouseAutoClickWindowFactory();
    ~AcMouseAutoClickWindowFactory();

    virtual void run();

private:
    void init();
    AcMouseAutoClickWindow* app;
};
/**************************************************************/

class AdScrollAreaViewFactory : public testAbstractFactory
{
public:
    AdScrollAreaViewFactory();
    ~AdScrollAreaViewFactory();

    virtual void run();

private:
    void init();
    AdScrollAreaView* app;
};
/**************************************************************/

class testFactoryProxy
{
public:
    bool registerFactory(testAbstractFactory* factory);
    bool contains(testAbstractFactory* factory);
    const QStringList& getAppNameList();
    testAbstractFactory* getFactory(const QString& appname);
    static testFactoryProxy* getInstance();

private:
    testFactoryProxy();
    void updateAppNameList();
    static testFactoryProxy* instance;
    QList<testAbstractFactory*> m_apps;
    QStringList applist;
};

#endif // TESTFACTORY_H
