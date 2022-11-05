#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QFont>
#include <QFontDialog>
MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QFile file("C:/Users/PULKIT BHATNAGAR/Documents/PulkitResume/Pulkit Resume.txt");

    if(!file.open(QFile:: ReadOnly | QFile:: Text)){
        QMessageBox::warning(this, "title", "file not open");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok){
        ui->plainTextEdit->setFont(font);
    } else return;
}

