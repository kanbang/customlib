#ifndef ACMOUSEAUTOCLICKWINDOW_H
#define ACMOUSEAUTOCLICKWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class AcMouseAutoClickWindow;
}

class AcMouseAutoClickWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit AcMouseAutoClickWindow(QWidget *parent = 0);
    ~AcMouseAutoClickWindow();
    
public slots:
    void executeMousePress();
    void OnStopClick();
    void OnBeginClick();

private:
    Ui::AcMouseAutoClickWindow *ui;
    QTimer *timer;
};

#endif // ACMOUSEAUTOCLICKWINDOW_H
