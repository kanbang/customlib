#ifndef EPDATABASE_GLOBAL_H
#define EPDATABASE_GLOBAL_H


#include <QtCore/qglobal.h>

#if defined(DATABASE_LIBRARY)
#  define DATABASE_EXPORT Q_DECL_EXPORT
#else
#  define DATABASE_EXPORT Q_DECL_IMPORT
#endif


#endif // EPDATABASE_GLOBAL_H
