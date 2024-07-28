#ifndef DIALOGONETEXT_H
#define DIALOGONETEXT_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class DialogOneText;
}

class DialogOneText : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOneText(QWidget *parent = nullptr, QString label_text = "Ingrese texto", bool password_visibility = 0);
    ~DialogOneText();
signals:
    void send_text(QString text);

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();

private:
    Ui::DialogOneText *ui;
    QLabel *label;
    QLineEdit *line_edit;
};

#endif // DIALOGONETEXT_H
