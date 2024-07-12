#ifndef DIALOGPASSWORD_H
#define DIALOGPASSWORD_H

#include <QDialog>

namespace Ui {
class DialogPassword;
}

class DialogPassword : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPassword(QWidget *parent = nullptr);
    ~DialogPassword();
signals:
    void expectedPass(QString pass);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogPassword *ui;
};

#endif // DIALOGPASSWORD_H
