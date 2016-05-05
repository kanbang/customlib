#ifndef DISPLAYTABLEFORM_H
#define DISPLAYTABLEFORM_H

#include <QWidget>
#include <tablemodel.h>

namespace Ui {
class DisplayTableForm;
}

class DisplayTableForm : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayTableForm(QWidget *parent = 0);
    ~DisplayTableForm();

public slots:
    void setTableName(const QString& name);

private:
    Ui::DisplayTableForm *ui;
    TableModel* m_model;
};

#endif // DISPLAYTABLEFORM_H
