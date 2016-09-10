#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "webobjectinstance.h"

namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();

private slots:
    void cursorMoved(int x, int y) ;

private:
    Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
