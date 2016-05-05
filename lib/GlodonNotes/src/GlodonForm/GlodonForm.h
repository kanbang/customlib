#ifndef GLODONFORM_H
#define GLODONFORM_H

#include <QMainWindow>
#include <glodonform_global.h>

namespace Ui {
class GlodonForm;
}

class GLODONFORMSHARED_EXPORT GlodonForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit GlodonForm(QWidget *parent = 0);
    ~GlodonForm();

    void initUI();
private:
    Ui::GlodonForm *ui;
};


#endif // GLODONFORM_H
