#ifndef DIALOGPORT_H
#define DIALOGPORT_H

#include <QDialog>

namespace Ui {
class DialogPort;
}

class DialogPort : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPort(QWidget *parent = nullptr);
    ~DialogPort();

signals:
    void port(QString port);

private slots:

    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

private:
    Ui::DialogPort *ui;
};

#endif // DIALOGPORT_H
