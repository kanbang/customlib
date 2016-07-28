#ifndef PMPHONEMATCH_H
#define PMPHONEMATCH_H
#include <QtCore>
#include "db.h"
#include "adaptor.h"
#include "matchinterface.h"
#include <QHash>

enum phoneType{
    opCellPhone,        // 手机
    opTelePhone,        // 固定电话
    opBankPhone,        // 服务电话 95588
    op400Phone,         // 400电话
    op10Phone,          // 10086
    op106Phone,         // 106 d的电话
    opPlusPhone,        // 6为的电话号码
    opOtherPhone        // 其他特殊号码
};

class Core : public QObject
{
    Q_OBJECT
public:
    Core(QObject* parent=0);

public slots:
    bool add(QString number);
    bool remove(QString number);
    QStringList get();
    bool check(QString number);
    bool checkHarassment(QString number);

signals:
    void numberAdded(QString);
    void numberRemoved(QString);

private:
    void initData();

    QString checkNum(const QString& number);
    bool checkNumber(const QString& number, const QStringList& list);

private:
    QStringList list;
    QStringList m_sHarass;
    Db* db;
    HarassDB* m_pHarassDb;

    QMap<phoneType, QRegExp> regExpMaps;
    QMap<phoneType, IPhoneAlgo*> algos;
};

#endif // PMPHONEMATCH_H
