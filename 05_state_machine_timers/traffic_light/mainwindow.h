#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtDebug>
#include <QMainWindow>
#include <QPixmap>
#include <QTimer>
#include <QStateMachine>
#include <QEventTransition>
#include <QSignalTransition>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QStateMachine *fsm;
    QState *green_state;
    QState *yellow_state;
    QState *red_state;
    QSignalTransition *t_green_to_yellow;
    QSignalTransition *t_yellow_to_red;
    QSignalTransition *t_red_to_green;


    QTimer *green_timer;
    QTimer *yellow_timer;
    QTimer *red_timer;

    int green_interval = 5000;
    int yellow_interval = 2000;
    int red_interval = 5000;

    QPixmap *pix;

public slots:
    void update_light();
};
#endif // MAINWINDOW_H
