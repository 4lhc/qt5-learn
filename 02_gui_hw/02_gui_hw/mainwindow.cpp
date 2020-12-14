#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Waiting!!!");
    /*ui->start_btn->setText("Start"); //set Start button text
    ui->progressBar->setValue(45);
*/
    //connect horizontal slider signal to progressbar
    //connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
    //        ui->progressBar, SLOT(setValue(int)));

    connect(ui->send_btn, SIGNAL(clicked()),
            this, SLOT(sendMessage()));

    connect(this, SIGNAL(messageSent(const Message &)),
            this, SLOT(setStatus()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendMessage()
{
    thisMessage = Message(ui->message_box->toPlainText(), thisMessage.headers());
    qDebug() << thisMessage;
    emit messageSent(thisMessage);
}

void MainWindow::setMessage(const Message &message)
{
    thisMessage = message;
    ui->message_box->setPlainText(thisMessage.body());
}

void MainWindow::setStatus()
{
    ui->statusbar->showMessage("Message Sent!!!");

}




void MainWindow::on_send_btn_clicked()
{
    //automatically created slot
   ui->send_btn->setText("Sent");
}

void MainWindow::on_actionQuit_triggered()
{
   QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "About Me", "This is me");

}

void MainWindow::on_actionColor_Picker_triggered()
{
    bool ok;
    QColor color = QColorDialog::getColor(Qt::yellow, this);

    if (&ok)
    {
        ui->message_box->setTextColor(color);
    }

}

void MainWindow::on_actionNew_triggered()
{
   //Creating File Dialog
   QString filename = QFileDialog::getOpenFileName(this, "Open a file");
   QFile file(filename);
   file.open(QIODevice::ReadOnly | QIODevice::Text);
   QTextStream in(&file);
   QString lines = in.readAll(); //Avoid using readAll with large files - use readlines instead
   ui->message_box->setText(lines);
}

void MainWindow::on_actionSave_triggered()
{
   QString filename = QFileDialog::getOpenFileName(this, "Open a file");
   QFile file(filename);
   file.open(QIODevice::ReadOnly | QIODevice::Text);
   QTextStream in(&file);

   int line_count = 0;
   while (!in.atEnd())
   {
       line_count += 1;
       QString lc = QString::number((line_count));
       QString line = in.readLine();
       lc.append(" >> ");
       lc.append(line);
       ui->message_box->append(lc);
   }




}
