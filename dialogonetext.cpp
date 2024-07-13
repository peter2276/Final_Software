#include "dialogonetext.h"
#include "ui_dialogonetext.h"

DialogOneText::DialogOneText(QWidget *parent, QString label_text, bool password_visibility)
    : QDialog(parent)
    , ui(new Ui::DialogOneText)
{
    ui->setupUi(this);
    line_edit = findChild<QLineEdit*>("lineEdit");
    if (password_visibility)
        line_edit->setEchoMode(QLineEdit::Password);
    label = findChild<QLabel*>("label");
    label->setText(label_text);
}

DialogOneText::~DialogOneText(){
    delete ui;
}

void DialogOneText::on_buttonBox_rejected(){
    this->close();
}

void DialogOneText::on_buttonBox_accepted(){
    QString text = line_edit->text();
    emit send_text(text);
    this->close();
}

