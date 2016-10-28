#include "arming.hpp"
#include "common/ui_arming.h"
#include <QProcess>

extern double move_set[4];

Arming::Arming(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arming)
{
    ui->setupUi(this);
}

Arming::~Arming()
{
    delete ui;
}

void Arming::on_buttonBox_accepted()
{
    move_set[3] = 1.0;
    QProcess::execute("rosrun mavros mavsafety arm");
}


void Arming::on_buttonBox_rejected()
{
    move_set[3] = 0.0;
}
