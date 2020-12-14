#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "message.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void messageSent(const Message &message);

public slots:
    void setMessage(const Message &message);
    void setStatus();

private slots:
    void sendMessage();

    void on_send_btn_clicked();

    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

    void on_actionColor_Picker_triggered();

    void on_actionNew_triggered();

    void on_actionSave_triggered();

private:
    Message thisMessage;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
