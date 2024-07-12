#include "dialogpassword.h"
#include "ui_dialogpassword.h"

DialogPassword::DialogPassword(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPassword)
{
    ui->setupUi(this);
}

DialogPassword::~DialogPassword()
{
    delete ui;
}

void DialogPassword::on_buttonBox_accepted()
{
    QString text = ui->lineEdit->text();
    emit expectedPass(text);
    this->close();
}


void DialogPassword::on_buttonBox_rejected()
{
    this->close();
}

