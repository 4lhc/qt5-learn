#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRect green_rect(100, 4, 63, 260);
    QRect yellow_rect(183, 4, 63, 260);
    QRect red_rect(266, 4, 63, 260);

    pix = new QPixmap(":/resource/img/traffic_light.jpg");
    QPixmap green_pix = pix->copy(green_rect);
    QPixmap yellow_pix = pix->copy(yellow_rect);
    QPixmap red_pix = pix->copy(red_rect);


    fsm = new QStateMachine(this);
    green_state = new QState();
    green_state->setObjectName("1");
    green_state->assignProperty(ui->label_pic, "pixmap", green_pix);
    yellow_state = new QState();
    yellow_state->setObjectName("2");
    yellow_state->assignProperty(ui->label_pic, "pixmap", yellow_pix);
    red_state = new QState();
    red_state->setObjectName("3");
    red_state->assignProperty(ui->label_pic, "pixmap", red_pix);

    green_timer = new QTimer(green_state);
    green_timer->setInterval(green_interval);
    yellow_timer = new QTimer(yellow_state);
    yellow_timer->setInterval(yellow_interval);
    red_timer = new QTimer(red_state);
    red_timer->setInterval(red_interval);

    green_state->addTransition(green_timer, &QTimer::timeout, yellow_state);
    QObject::connect(green_state, &QAbstractState::entered, green_timer, QOverload<>::of(&QTimer::start));
    QObject::connect(green_state, &QAbstractState::entered, this, &MainWindow::update_light);

    yellow_state->addTransition(yellow_timer, &QTimer::timeout, red_state);
    QObject::connect(yellow_state, &QAbstractState::entered, yellow_timer, QOverload<>::of(&QTimer::start));
    QObject::connect(yellow_state, &QAbstractState::entered, this, &MainWindow::update_light);

    red_state->addTransition(red_timer, &QTimer::timeout, green_state);
    QObject::connect(red_state, &QAbstractState::entered, red_timer, QOverload<>::of(&QTimer::start));
    QObject::connect(red_state, &QAbstractState::entered, this, &MainWindow::update_light);

    fsm->addState(green_state);
    fsm->addState(yellow_state);
    fsm->addState(red_state);
    fsm->setInitialState(green_state);
    fsm->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_light()
{
    qDebug() << "Current State:" << fsm->configuration(); //print current state
    qDebug() << green_timer->remainingTime();
    qDebug() << green_timer->interval();
}

