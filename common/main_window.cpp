/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date November 2010
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include <QProcess>
#include "main_window.hpp"

double move_set[4]={0.0,0.0,0.0,0.0};
bool arm_flag = 0;
using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(QNode *node, QWidget *parent) :
    QMainWindow(parent),
    qnode(node)
{

	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    armDis = new Arming;
    qnode->on_init();
}

MainWindow::~MainWindow()
{

}


void MainWindow::on_Forward_clicked()
{
    move_set[0] = move_set[0] + 0.2;
}

void MainWindow::on_Back_clicked()
{
    move_set[0] = move_set[0] - 0.2;
}

void MainWindow::on_Left_clicked()
{
    move_set[1] = move_set[1] - 0.2;
}

void MainWindow::on_Right_clicked()
{
    move_set[1] = move_set[1] + 0.2;
}

void MainWindow::on_Up_clicked()
{
    move_set[2] = move_set[2] + 0.2;
}

void MainWindow::on_Down_clicked()
{
    move_set[2] = move_set[2] - 0.2;
    if(move_set[2]<=0.0)
        move_set[2] = 0.0;
}

void MainWindow::on_Takeoff_clicked()
{
    move_set[2] = 2;
}

void MainWindow::on_Land_clicked()
{
    move_set[2] = 0;
}

void MainWindow::on_ReturnHome_clicked()
{
    move_set[0] = 0.0;
    move_set[1] = 0.0;
    move_set[2] = 0.0;
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    switch(k->key())
    {
        case Key_Q: move_set[2] = move_set[2] + 0.2; break;
        case Key_E: move_set[2] = move_set[2] - 0.2; break;
        case Key_W: move_set[0] = move_set[0] + 0.2; break;
        case Key_S: move_set[0] = move_set[0] - 0.2; break;
        case Key_A: move_set[1] = move_set[1] - 0.2; break;
        case Key_D: move_set[1] = move_set[1] + 0.2; break;
        default: break;
    }
}


void MainWindow::on_Arm_clicked()
{
    if(move_set[3]==0.0)
    {
        armDis->show();
    }
}

void MainWindow::on_Disarm_clicked()
{
    move_set[3] = 0.0;
    QProcess::execute("rosrun mavros mavsafety disarm");
}


