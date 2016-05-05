#ifndef EPMODEL_GLOBAL_H
#define EPMODEL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MODEL_LIBRARY)
#  define MODEL_EXPORT Q_DECL_EXPORT
#else
#  define MODEL_EXPORT Q_DECL_IMPORT
#endif


#endif // EPMODEL_GLOBAL_H
