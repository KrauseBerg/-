#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>

namespace Ui {
class calculator;
}

class calculator : public QDialog
{
    Q_OBJECT

public:
    explicit calculator(QWidget *parent = 0);
    ~calculator();
    static QString number(double);
    QString str;
    double perem;
    int act;
    bool wait;
private slots:
    void showNumber();
    void clear();
    void c_plus();
    void c();
    void s_sqr();
    void c_ravno();
    void c_minus();
    void c_delit();
    void c_star();

private:
    Ui::calculator *ui;
};



#endif // CALCULATOR_H
