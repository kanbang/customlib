#ifndef SHAREDLIB_GLOBAL_H
#define SHAREDLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SHAREDLIB_LIBRARY)
#  define SHAREDLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SHAREDLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SHAREDLIB_GLOBAL_H
