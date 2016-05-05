#ifndef NETWORKWINDOWAPP_H
#define NETWORKWINDOWAPP_H

#include <QMainWindow>
#include <ENAllHeader.h>
#include <QtGui>

namespace Ui {
class networkWindowApp;
}

class networkWindowApp : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit networkWindowApp(QWidget *parent = 0);
    ~networkWindowApp();

    void initAppList();
    void testIdea();

protected:
    void mousePressEvent(QMouseEvent *);

private slots:
    void run(QListWidgetItem* item);
    void mouseClick();

private:
    Ui::networkWindowApp *ui;

    QStringList applist;
    QTimer *timer;
};

#endif // NETWORKWINDOWAPP_H
