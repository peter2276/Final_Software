#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialogpassword.h"
#include "dialogport.h"
#include "dialognewpass.h"
#include <iostream>

MainWindow::MainWindow(SystemManager *model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    manager = model;
    ui->setupUi(this);
    alarm_state_label = findChild<QLabel*>("AlarmState");
    alarm_state_label->setText(QString::fromStdString(manager->CheckAlarm()));
    alarm_addsensor_button = findChild<QPushButton*>("AlarmAddsensorButton");
    alarm_changepass_button = findChild<QPushButton*>("AlarmChangepassButton");
    alarm_toggle_button = findChild<QPushButton*>("AlarmToggleButton");
    alarm_create_button = findChild<QPushButton*>("AlarmCreateButton");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::toggleAlarm(QString pass){
    manager->ToggleAlarm(pass.toUtf8().constData());
    alarm_state_label->setText(QString::fromStdString(manager->CheckAlarm()));
    std::cout << pass.toUtf8().constData() << std::endl;
}

void MainWindow::createAlarm(QString port){
    manager->CreateAlarm(port.toUtf8().constData());
    alarm_toggle_button->setDisabled(0);
    alarm_changepass_button->setDisabled(0);
    alarm_addsensor_button->setDisabled(0);
    alarm_state_label->setDisabled(0);
    alarm_create_button->setDisabled(1);
}

void MainWindow::on_AlarmToggleButton_clicked()
{
    DialogPassword QPassDialog(this);
    QObject::connect(&QPassDialog,&DialogPassword::expectedPass,this,&MainWindow::toggleAlarm);
    QPassDialog.exec();
}


void MainWindow::on_AlarmCreateButton_clicked()
{
    DialogPort QPortDialog(this);
    QObject::connect(&QPortDialog,&DialogPort::port,this,&MainWindow::createAlarm);
    QPortDialog.exec();
}

void MainWindow::changeAlarmPass(QString actual_pass, QString new_pass){
    manager->SetPassword(actual_pass.toUtf8().constData(), new_pass.toUtf8().constData());
}

void MainWindow::on_AlarmChangepassButton_clicked()
{
    DialogNewPass QNewPassDialog(this);
    QObject::connect(&QNewPassDialog,&DialogNewPass::changePass,this,&MainWindow::changeAlarmPass);
    QNewPassDialog.exec();
}

