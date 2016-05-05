#ifndef GLODONTESTLIB_GLOBAL_H
#define GLODONTESTLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WIDGET_LIBRARY)
#  define WIDGETSHARED_EXPORT Q_DECL_EXPORT
#else
#  define WIDGETSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GLODONTESTLIB_GLOBAL_H
