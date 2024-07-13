#include "dialog2ports.h"
#include "ui_dialog2ports.h"

Dialog2Ports::Dialog2Ports(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog2Ports)
{
    ui->setupUi(this);
}

Dialog2Ports::~Dialog2Ports()
{
    delete ui;
}

void Dialog2Ports::on_buttonBox_2_accepted()
{
    QString text_0 = ui->lineEdit->text();
    QString text_1 = ui->lineEdit_2->text();
    emit get2ports(text_0, text_1);
    this->close();
}


void Dialog2Ports::on_buttonBox_2_rejected()
{
    this->close();
}

