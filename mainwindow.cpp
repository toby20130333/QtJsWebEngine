#include "mainwindow.h"
#include "ui_mainwindow.h"

//
// This program has a widget with its own class (HtmlPage) based on QWebEngine
// The HtmlPage calls up a single html file, which contains JavaScript
//
// The Javascript has a handler which places a large dot when the cursor is clicked
// The Javascript then calls (asynchronously) a C++ function
// The C++ function emits a message to the mainwindow to update the X and Y coordinates on the form
// The C++ function then calls (asynchronously) the Javascript to place a small dot at the same X and Y coordinates
//

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    connect(WebObjectInstance::instance(),SIGNAL(signalCursorMoved(int,int)),this,SLOT(cursorMoved(int,int)));
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::cursorMoved(int x, int y)
{
    ui->labelX->setText(QString("%1").arg(x)) ;
    ui->labelY->setText(QString("%1").arg(y)) ;
}
