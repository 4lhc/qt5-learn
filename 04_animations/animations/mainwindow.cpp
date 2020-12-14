#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->animated_btn1, SIGNAL(clicked()),
            this, SLOT(start_parallel_animation()));
    connect(ui->animated_btn2, SIGNAL(clicked()),
            this, SLOT(start_sequential_animation()));


    animation1 = new QPropertyAnimation(ui->animated_btn1, "geometry");
    animation1->setDuration(2000);
    animation1->setStartValue(ui->animated_btn1->geometry());
    animation1->setEndValue(QRect(200, 200, 100, 50));

    //animation1->start(); //individual animations

    animation2 = new QPropertyAnimation(ui->animated_btn2, "geometry");
    animation2->setDuration(2000);
    animation2->setStartValue(ui->animated_btn2->geometry());
    animation2->setEndValue(QRect(300, 200, 100, 50));

    //animation2->start();

    animation3 = new QPropertyAnimation(ui->animated_btn3, "geometry");
    animation3->setDuration(2000);
    animation3->setStartValue(ui->animated_btn3->geometry());
    animation3->setEndValue(QRect(400, 200, 100, 50));

    //animation3->start();






    /*//Easing Curve
    QEasingCurve curve;
    curve.setType(QEasingCurve::OutElastic);
    animation1->setEasingCurve(curve);

    curve.setAmplitude(2.0);
    curve.setPeriod((0.25));
    animation->setLoopCount(-1); //inf loop anim using -1 else use an int
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start_parallel_animation()
{
    //Parallel Animation
    animation_grp = new QParallelAnimationGroup;
    animation_grp->addAnimation((animation1));
    animation_grp->addAnimation((animation2));
    animation_grp->addAnimation((animation3));
    animation_grp->start();
}


void MainWindow::start_sequential_animation()
{
    //Sequential Animation
    animation_grp_seq = new QSequentialAnimationGroup;
    animation_grp_seq->addAnimation((animation1));
    animation_grp_seq->addAnimation((animation2));
    animation_grp_seq->addAnimation((animation3));
    animation_grp_seq->start();
}
