#ifndef ARMING_H
#define ARMING_H

#include <QDialog>

namespace Ui {
class Arming;
}

class Arming : public QDialog
{
    Q_OBJECT

public:
    explicit Arming(QWidget *parent = 0);
    ~Arming();

private Q_SLOTS:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();

private:
    Ui::Arming *ui;
};

#endif // ARMING_H
