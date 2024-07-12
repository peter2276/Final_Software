#ifndef DIALOGNEWPASS_H
#define DIALOGNEWPASS_H

#include <QDialog>

namespace Ui {
class DialogNewPass;
}

class DialogNewPass : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewPass(QWidget *parent = nullptr);
    ~DialogNewPass();
signals:
    void changePass(QString actual_pass, QString new_pass);

private slots:
    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

private:
    Ui::DialogNewPass *ui;
};

#endif // DIALOGNEWPASS_H
