#ifndef DIALOGCOMBOBOX_H
#define DIALOGCOMBOBOX_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>

namespace Ui {
class DialogComboBox;
}

class DialogComboBox : public QDialog
{
    Q_OBJECT

public:
    DialogComboBox(QWidget *parent = nullptr, QString label_text = "Ingrese texto", std::vector<std::string> combo_text = std::vector<std::string> ());
    ~DialogComboBox();
signals:
    void send_text(QString text);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogComboBox *ui;
    QLabel *label;
    QComboBox *combobox;
};

#endif // DIALOGCOMBOBOX_H
