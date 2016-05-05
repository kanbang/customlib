#ifndef TESTWINDOWAPP_H
#define TESTWINDOWAPP_H

#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class TestWindowApp;
}

class TestWindowApp : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TestWindowApp(QWidget *parent = 0);
    ~TestWindowApp();
    
private slots:
    void run(QListWidgetItem* item);

private:
    Ui::TestWindowApp *ui;
};

#endif // TESTWINDOWAPP_H
