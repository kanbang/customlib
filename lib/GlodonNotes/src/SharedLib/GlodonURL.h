#ifndef GLODONURL_H
#define GLODONURL_H

#include "sharedlib_global.h"
#include <QList>

class AbstractExetension;

class SHAREDLIBSHARED_EXPORT AbstractUIPlugin
{
public:
    AbstractUIPlugin();
    ~AbstractUIPlugin();

    virtual void doRegisterExtension() = 0;

private:
    QList<AbstractExetension*> m_pExtensions;
};

class SHAREDLIBSHARED_EXPORT TestUIPlugin : public AbstractUIPlugin
{
public:
    TestUIPlugin();

    virtual void doRegisterExtension();
};

class SHAREDLIBSHARED_EXPORT AbstractFrame
{
public:

private:
    AbstractFrame();
    ~AbstractFrame();
};

class SHAREDLIBSHARED_EXPORT AbstractExetension
{
public:

private:
    AbstractExetension();
    ~AbstractExetension();
};

class SHAREDLIBSHARED_EXPORT GlodonURL
{
public:
    GlodonURL();
};

#endif // GLODONURL_H
