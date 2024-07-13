#ifndef DIALOG2PORTS_H
#define DIALOG2PORTS_H

#include <QDialog>

namespace Ui {
class Dialog2Ports;
}

class Dialog2Ports : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2Ports(QWidget *parent = nullptr);
    ~Dialog2Ports();
signals:
    void get2ports(QString port_act, QString port_sensor);

private slots:
    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

private:
    Ui::Dialog2Ports *ui;
};

#endif // DIALOG2PORTS_H
