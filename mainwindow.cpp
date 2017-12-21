#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include "convertnumber.h"
#include <QString>
#include <QMessageBox>
#include "swap.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //change title
    QWidget::setWindowTitle("Convert 10 to binary and hexa number");

    // create event
    connect(ui->btnConvert, SIGNAL(clicked()), this, SLOT(convertButton()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(cancelButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::convertButton()
{
    QString tmp = ui->txtDecNumber->text();
    if(tmp.isEmpty())
    {
        QMessageBox::warning(this, "Error", "No number");
        return;
    }

    int number, flag = 0;
    number = tmp.toInt();

    if(number < -128)
    {
        QMessageBox::warning(this, "error", "Number less than -128");
        cancelButton();
        return;
    }

    if(number > 255){
        QMessageBox::warning(this, "error", "Number great than 255");
        cancelButton();
        return;
    }

    if(number < 0)
    {
        number = 256 + number;
        flag = 1;
    }

    char result[9] = {'0', '0', '0', '0', '0', '0', '0', '0', '\0'};
    convertNumberToBin(number, result);
    swap(result, result, 8);
    if(flag)
    {
        result[0] = '1';
    }
    ui->txtBinNumber->setText(result);


    char result2[3] = {'0', '0', '\0'};
    convertNumberToHex(number, result2);
    swap(result2, result2, 2);
    ui->txtHexaNumber->setText(result2);
}

void MainWindow::cancelButton()
{
    ui->txtDecNumber->setText("");
    ui->txtBinNumber->setText("");
    ui->txtHexaNumber->setText("");
}
