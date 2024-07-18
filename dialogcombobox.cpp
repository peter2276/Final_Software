#include "dialogcombobox.h"
#include "ui_dialogcombobox.h"
#include <iostream>
#include <QStringList>
#define _GLIBCXX_USE_CXX11_ABI 0
#include <vector>
#include <string>

DialogComboBox::DialogComboBox(QWidget *parent, QString label_text, std::vector<std::string> combo_text)
    : QDialog(parent)
    , ui(new Ui::DialogComboBox)
{
    ui->setupUi(this);
    label = findChild<QLabel*>("label");
    label->setText(label_text);
    combobox = findChild<QComboBox*>("comboBox");
    QStringList list;
    for (auto it = combo_text.begin(); it != combo_text.end(); it++){
        std::cout << "Aca" << *it << std::endl;
        list += QString((*it));
        //combobox->addItem("QString(*it)",0);
    }
    combobox->addItems(list);
}

DialogComboBox::~DialogComboBox()
{
    delete ui;
}

void DialogComboBox::on_buttonBox_accepted()
{
    QString text = combobox->currentText();
    emit send_text(text);
    this->close();
}

void DialogComboBox::on_buttonBox_rejected()
{
    this->close();
}

