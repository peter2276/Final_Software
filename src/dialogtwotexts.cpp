#include "dialogtwotexts.h"
#include "ui_dialogtwotexts.h"

DialogTwoTexts::DialogTwoTexts(QWidget *parent, QString label_text_1, QString label_text_2, bool password_visibility)
    : QDialog(parent)
    , ui(new Ui::DialogTwoTexts)
{
    ui->setupUi(this);
    line_edit_1 = findChild<QLineEdit*>("lineEdit");
    line_edit_2 = findChild<QLineEdit*>("lineEdit_2");
    if (password_visibility){
        line_edit_1->setEchoMode(QLineEdit::Password);
        line_edit_2->setEchoMode(QLineEdit::Password);
    }
    label_1 = findChild<QLabel*>("label");
    label_2 = findChild<QLabel*>("label_2");
    label_1->setText(label_text_1);
    label_2->setText(label_text_2);
}

DialogTwoTexts::~DialogTwoTexts()
{
    delete ui;
}

void DialogTwoTexts::on_buttonBox_rejected(){
    this->close();
}


void DialogTwoTexts::on_buttonBox_accepted(){
    QString text_1 = line_edit_1->text();
    QString text_2 = line_edit_2->text();
    emit send_text(text_1, text_2);
    this->close();
}

