#include "dialogport.h"
#include "ui_dialogport.h"

DialogPort::DialogPort(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPort)
{
    ui->setupUi(this);
}

DialogPort::~DialogPort()
{
    delete ui;
}


void DialogPort::on_buttonBox_2_accepted()
{
    QString text = ui->lineEdit->text();
    emit port(text);
    this->close();
}


void DialogPort::on_buttonBox_2_rejected()
{
    this->close();
}

