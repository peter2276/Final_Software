#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "systemmanager.h"
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(SystemManager *model, QWidget *parent = nullptr);
    ~MainWindow(); 

private slots:
    void toggleAlarm(QString pass);
    void createAlarm(QString port);
    void changeAlarmPass(QString actual_pass, QString new_pass);
    void on_AlarmToggleButton_clicked();

    void on_AlarmCreateButton_clicked();

    void on_AlarmChangepassButton_clicked();

private:
    Ui::MainWindow *ui;
    SystemManager *manager;
    QLabel *alarm_state_label;
    QPushButton *alarm_toggle_button;
    QPushButton *alarm_create_button;
    QPushButton *alarm_changepass_button;
    QPushButton *alarm_addsensor_button;
};
#endif // MAINWINDOW_H
