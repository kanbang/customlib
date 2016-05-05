#ifndef GLODONSERVICEDESIGN_H
#define GLODONSERVICEDESIGN_H

#include "sharedlib_global.h"
#include <QList>

class AbstractServicePluginFacade;

class SHAREDLIBSHARED_EXPORT Facade
{
public:
    Facade();

private:
    QList<AbstractServicePluginFacade*> m_pluginFacades;
};


class SHAREDLIBSHARED_EXPORT AbstractServicePluginFacade
{
public:
    AbstractServicePluginFacade();
    ~AbstractServicePluginFacade();
};

class SHAREDLIBSHARED_EXPORT AbstractServicePlugin
{
public:
    AbstractServicePlugin();
    ~AbstractServicePlugin();
};

class SHAREDLIBSHARED_EXPORT AbstractService
{
public:
    AbstractService();
    ~AbstractService();
};

#endif // GLODONSERVICEDESIGN_H
