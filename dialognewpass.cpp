#include "dialognewpass.h"
#include "ui_dialognewpass.h"

DialogNewPass::DialogNewPass(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogNewPass)
{
    ui->setupUi(this);
}

DialogNewPass::~DialogNewPass()
{
    delete ui;
}

void DialogNewPass::on_buttonBox_2_accepted()
{
    QString text_0 = ui->lineEdit->text();
    QString text_1 = ui->lineEdit_2->text();
    emit changePass(text_0, text_1);
    this->close();
}

void DialogNewPass::on_buttonBox_2_rejected()
{
    this->close();
}

