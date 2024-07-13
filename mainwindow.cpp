#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialogonetext.h"
#include "dialogtwotexts.h"
#include <QMessageBox>

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

    heater_create_button = findChild<QPushButton*>("HeaterCreateButton");
    heater_toggle_button = findChild<QPushButton*>("HeaterToggleButton");
    heater_set_button = findChild<QPushButton*>("HeaterSetButton");
    heater_state_label = findChild<QLabel*>("HeaterState");
    heater_objtemp_label = findChild<QLabel*>("HeaterTargetTemp");
    heater_temp_label = findChild<QLabel*>("HeaterTemp");

    lights_list = findChild<QListWidget*>("LightsListWidget");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::toggleAlarm(QString pass){
    if (manager->ToggleAlarm(pass.toUtf8().constData()))
        alarm_state_label->setText(QString::fromStdString(manager->CheckAlarm()));
    else
        QMessageBox::warning(this, "ERROR", "Contraseña incorrecta", QMessageBox::Ok);
}

void MainWindow::createAlarm(QString port){
    if (manager->CreateAlarm(port.toUtf8().constData())){
        alarm_toggle_button->setDisabled(0);
        alarm_changepass_button->setDisabled(0);
        alarm_addsensor_button->setDisabled(0);
        alarm_state_label->setDisabled(0);
        alarm_create_button->setDisabled(1);
    }
    else
       QMessageBox::warning(this, "ERROR", "Puerto incorrecto", QMessageBox::Ok);
}

void MainWindow::on_AlarmToggleButton_clicked()
{
    DialogOneText QPassDialog(this, "Ingrese contraseña:", 1);
    QObject::connect(&QPassDialog,&DialogOneText::send_text,this,&MainWindow::toggleAlarm);
    QPassDialog.exec();
}


void MainWindow::on_AlarmCreateButton_clicked()
{
    DialogOneText QPortDialog(this, "Ingrese el puerto de la alarma:");
    QObject::connect(&QPortDialog,&DialogOneText::send_text,this,&MainWindow::createAlarm);
    QPortDialog.exec();
}

void MainWindow::changeAlarmPass(QString actual_pass, QString new_pass){
    if (!manager->SetPassword(actual_pass.toUtf8().constData(), new_pass.toUtf8().constData()))
        QMessageBox::warning(this, "ERROR", "Contraseña incorrecta", QMessageBox::Ok);
}

void MainWindow::on_AlarmChangepassButton_clicked()
{
    DialogTwoTexts QNewPassDialog(this, "Ingrese clave actual:", "Ingrese nueva clave:", 1);
    QObject::connect(&QNewPassDialog,&DialogTwoTexts::send_text,this,&MainWindow::changeAlarmPass);
    QNewPassDialog.exec();
}

void MainWindow::createAlarmSensor(QString port){
    if (!manager->AddSensor(port.toUtf8().constData()))
        QMessageBox::warning(this, "ERROR", "Puerto incorrecto", QMessageBox::Ok);
}

void MainWindow::on_AlarmAddsensorButton_clicked()
{
    DialogOneText QPortDialog(this, "Ingrese el puerto del nuevo sensor:");
    QObject::connect(&QPortDialog,&DialogOneText::send_text,this,&MainWindow::createAlarm);
    QPortDialog.exec();
}

void MainWindow::createHeater(QString port_act, QString port_sensor){
    if (manager->CreateHeater(port_act.toUtf8().constData(), port_sensor.toUtf8().constData())){
        heater_create_button->setDisabled(1);
        heater_toggle_button->setDisabled(0);
        heater_set_button->setDisabled(0);
        heater_state_label->setDisabled(0);
        heater_objtemp_label->setDisabled(0);
        heater_temp_label->setDisabled(0);
    }
    else
        QMessageBox::warning(this, "ERROR", "Puerto incorrecto", QMessageBox::Ok);
}

void MainWindow::on_HeaterCreateButton_clicked()
{
    DialogTwoTexts QPortDialog(this, "Ingrese el puerto del actuador:", "Ingrese el puerto del sensor:");
    QObject::connect(&QPortDialog,&DialogTwoTexts::send_text,this,&MainWindow::createHeater);
    QPortDialog.exec();
}


void MainWindow::on_HeaterToggleButton_clicked()
{
    manager->ToggleHeater();
    manager->GetHeaterState() ? heater_state_label->setText("Estado: Encendido") : heater_state_label->setText("Estado: Apagado");
}


void MainWindow::on_HeaterSetButton_clicked()
{
    DialogOneText QTempDialog(this, "Ingrese la temperatura deseada:");
    QObject::connect(&QTempDialog,&DialogOneText::send_text,this,&MainWindow::setTargetTemp);
    QTempDialog.exec();
}

void MainWindow::setTargetTemp(QString temp){
    bool ok;
    int temp_int = temp.toInt(&ok);
    if (ok){
        manager->SetTemp(temp_int);
        heater_objtemp_label->setText("Temperatura objetivo: " + temp);
    }
    else
        QMessageBox::information(this, "ERROR", "Temperatura no valida", QMessageBox::Ok);
}

void MainWindow::on_LightsCreateButton_clicked(){
    DialogTwoTexts QCreateLightsDialog(this, "Ingrese el puerto:", "Ingrese el nombre de la lampara:");
    QObject::connect(&QCreateLightsDialog,&DialogTwoTexts::send_text,this,&MainWindow::createlights);
    QCreateLightsDialog.exec();
}

void MainWindow::createlights(QString port, QString name){
    if (manager->CreateLight(port.toUtf8().constData())){
        QListWidgetItem *item = new QListWidgetItem(name);
        item->setBackground(Qt::red);
        lights_list->addItem(item);
    }
    else
        QMessageBox::warning(this, "ERROR", "Puerto incorrecto", QMessageBox::Ok);
}

void MainWindow::on_LightsListWidget_itemActivated(QListWidgetItem *item)
{
    int id = lights_list->currentRow();
    if (manager->GetLightState(id)){
        item->setBackground(Qt::red);
        manager->LightOff(id);
    }
    else {
        item->setBackground(Qt::green);
        manager->LightOn(id);
    }
}

