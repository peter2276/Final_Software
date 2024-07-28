#ifndef DIALOGTWOTEXTS_H
#define DIALOGTWOTEXTS_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class DialogTwoTexts;
}

class DialogTwoTexts : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTwoTexts(QWidget *parent = nullptr, QString label_text_1 = "Ingrese texto", QString label_text_2 = "Ingrese texto", bool password_visibility = 0);
    ~DialogTwoTexts();
signals:
    void send_text(QString text_1, QString text_2);

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();

private:
    Ui::DialogTwoTexts *ui;
    QLabel *label_1;
    QLineEdit *line_edit_1;
    QLabel *label_2;
    QLineEdit *line_edit_2;
};

#endif // DIALOGTWOTEXTS_H
