#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter mytext(this);
    mytext.setFont(QFont("Times", 16, QFont::Bold));
    mytext.drawText(QPoint(20, 20), "Hello Painter!!");


    QTextDocument document;
    QRect rect(0, 0, 250, 300);
    mytext.translate(300, 500);

    document.setHtml("<span style=' font-size:30pt; font-weight:600; color:#aa0000;'>TextLabel</span>");
    document.drawContents(&mytext, rect);

}

