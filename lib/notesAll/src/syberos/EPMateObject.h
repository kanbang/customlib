#ifndef EPMATEOBJECT_H
#define EPMATEOBJECT_H

#include <QObject>
#include <QString>
#include <QDate>

class EPMateObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ getId WRITE setId NOTIFY valueChanged)
//    Q_PROPERTY(QWidget* widget READ getWidget WRITE setWidget)

public:
    explicit EPMateObject(QObject *parent = 0);
    void setId(const QString &newId);
    const QString& getId() const;
    void setWidget(QWidget* widget);
    QWidget* getWidget();

    static void execute();
signals:
    void valueChanged(const QString& newId);

public slots:
    void slotValueChange(const QString& id);

private:
    QString _id;
    QWidget* m_widget;
};

//class Customer : public QObject
//{
//    Q_OBJECT

//    Q_PROPERTY(QString id READ getId WRITE setId NOTIFY valueChanged);
//    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY valueChanged);

//public:
//    enum CustomerType
//    { Corporate, Individual, Educational, Goverment };
//    Q_ENUMS(CustomerType);

//    explicit Customer(const QString name = QString(), QObject *parent = 0);

//    QString getId() const ;
//    void setType(CustomerType newType);
//    void setType(QString newType);

//signals:
//    void addressChanged(QString newAddress);
//    void phoneChanged(QString newphone);
//    void typeChanged(CustomerType type);
//    void valueChanged(QString propertyName, QVariant newValue, QVariant oldValue = QVariant());

//private:
//    QString m_id;
//    QString m_name;
//    QString m_address;
//    QString m_phone;
//    QDate   m_date;
//    CustomerType m_type;
//};

#endif // EPMATEOBJECT_H
