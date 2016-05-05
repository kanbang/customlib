#ifndef THREADWINDOWAPP_H
#define THREADWINDOWAPP_H

#include <QMainWindow>
#include <ETAllHeader.h>

namespace Ui {
class threadWindowApp;
}

class threadWindowApp : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit threadWindowApp(QWidget *parent = 0);
    ~threadWindowApp();
    void sendSignal(){emit emitSignal();}

signals:
    void emitSignal();

private slots:
    void run(QListWidgetItem* item);

private:
    Ui::threadWindowApp *ui;
};

#endif // THREADWINDOWAPP_H
