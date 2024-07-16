/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Alarm;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *AlarmCreateButton;
    QPushButton *AlarmToggleButton;
    QPushButton *AlarmChangepassButton;
    QPushButton *AlarmAddsensorButton;
    QLabel *AlarmState;
    QWidget *Heater;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *HeaterCreateButton;
    QPushButton *HeaterSetButton;
    QPushButton *HeaterToggleButton;
    QLabel *HeaterTargetTemp;
    QLabel *HeaterState;
    QLabel *HeaterTemp;
    QWidget *Lights;
    QListWidget *LightsListWidget;
    QPushButton *LightsCreateButton;
    QPushButton *LightsDeleteButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(378, 299);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 20, 331, 261));
        tabWidget->setMovable(false);
        Alarm = new QWidget();
        Alarm->setObjectName("Alarm");
        layoutWidget = new QWidget(Alarm);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 100, 291, 116));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        AlarmCreateButton = new QPushButton(layoutWidget);
        AlarmCreateButton->setObjectName("AlarmCreateButton");

        verticalLayout->addWidget(AlarmCreateButton);

        AlarmToggleButton = new QPushButton(layoutWidget);
        AlarmToggleButton->setObjectName("AlarmToggleButton");
        AlarmToggleButton->setEnabled(false);

        verticalLayout->addWidget(AlarmToggleButton);

        AlarmChangepassButton = new QPushButton(layoutWidget);
        AlarmChangepassButton->setObjectName("AlarmChangepassButton");
        AlarmChangepassButton->setEnabled(false);

        verticalLayout->addWidget(AlarmChangepassButton);

        AlarmAddsensorButton = new QPushButton(layoutWidget);
        AlarmAddsensorButton->setObjectName("AlarmAddsensorButton");
        AlarmAddsensorButton->setEnabled(false);

        verticalLayout->addWidget(AlarmAddsensorButton);

        AlarmState = new QLabel(Alarm);
        AlarmState->setObjectName("AlarmState");
        AlarmState->setEnabled(false);
        AlarmState->setGeometry(QRect(230, 50, 61, 21));
        tabWidget->addTab(Alarm, QString());
        Heater = new QWidget();
        Heater->setObjectName("Heater");
        verticalLayoutWidget = new QWidget(Heater);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(70, 90, 171, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        HeaterCreateButton = new QPushButton(verticalLayoutWidget);
        HeaterCreateButton->setObjectName("HeaterCreateButton");

        verticalLayout_2->addWidget(HeaterCreateButton);

        HeaterSetButton = new QPushButton(verticalLayoutWidget);
        HeaterSetButton->setObjectName("HeaterSetButton");
        HeaterSetButton->setEnabled(false);

        verticalLayout_2->addWidget(HeaterSetButton);

        HeaterToggleButton = new QPushButton(verticalLayoutWidget);
        HeaterToggleButton->setObjectName("HeaterToggleButton");
        HeaterToggleButton->setEnabled(false);

        verticalLayout_2->addWidget(HeaterToggleButton);

        HeaterTargetTemp = new QLabel(Heater);
        HeaterTargetTemp->setObjectName("HeaterTargetTemp");
        HeaterTargetTemp->setEnabled(false);
        HeaterTargetTemp->setGeometry(QRect(86, 20, 151, 20));
        HeaterState = new QLabel(Heater);
        HeaterState->setObjectName("HeaterState");
        HeaterState->setEnabled(false);
        HeaterState->setGeometry(QRect(86, 60, 151, 20));
        HeaterTemp = new QLabel(Heater);
        HeaterTemp->setObjectName("HeaterTemp");
        HeaterTemp->setEnabled(false);
        HeaterTemp->setGeometry(QRect(86, 40, 151, 20));
        tabWidget->addTab(Heater, QString());
        Lights = new QWidget();
        Lights->setObjectName("Lights");
        LightsListWidget = new QListWidget(Lights);
        LightsListWidget->setObjectName("LightsListWidget");
        LightsListWidget->setGeometry(QRect(20, 40, 256, 192));
        LightsCreateButton = new QPushButton(Lights);
        LightsCreateButton->setObjectName("LightsCreateButton");
        LightsCreateButton->setGeometry(QRect(20, 10, 131, 18));
        LightsDeleteButton = new QPushButton(Lights);
        LightsDeleteButton->setObjectName("LightsDeleteButton");
        LightsDeleteButton->setGeometry(QRect(160, 10, 131, 18));
        tabWidget->addTab(Lights, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        AlarmCreateButton->setText(QCoreApplication::translate("MainWindow", "Crear Alarma", nullptr));
        AlarmToggleButton->setText(QCoreApplication::translate("MainWindow", "Armar/Desarmar", nullptr));
        AlarmChangepassButton->setText(QCoreApplication::translate("MainWindow", "Cambiar contrase\303\261a", nullptr));
        AlarmAddsensorButton->setText(QCoreApplication::translate("MainWindow", "Agregar Sensor", nullptr));
        AlarmState->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Alarm), QCoreApplication::translate("MainWindow", "Alarma", nullptr));
        HeaterCreateButton->setText(QCoreApplication::translate("MainWindow", "Crear Calefacci\303\263n", nullptr));
        HeaterSetButton->setText(QCoreApplication::translate("MainWindow", "Setear T\302\260 Objetivo", nullptr));
        HeaterToggleButton->setText(QCoreApplication::translate("MainWindow", "Prender/Apagar", nullptr));
        HeaterTargetTemp->setText(QCoreApplication::translate("MainWindow", "Temperatura objetivo : 0", nullptr));
        HeaterState->setText(QCoreApplication::translate("MainWindow", "Estado: Apagado", nullptr));
        HeaterTemp->setText(QCoreApplication::translate("MainWindow", "Temperatura actual: 0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Heater), QCoreApplication::translate("MainWindow", "Calefacci\303\263n", nullptr));
        LightsCreateButton->setText(QCoreApplication::translate("MainWindow", "Crear nueva lampara", nullptr));
        LightsDeleteButton->setText(QCoreApplication::translate("MainWindow", "Eliminar lampara", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Lights), QCoreApplication::translate("MainWindow", "Luces", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
