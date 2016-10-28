/**
 * @file common/main_window.hpp
 *
 * @brief Qt based gui for eros_qtalker.
 *
 * @date November 2010
 **/
#ifndef QTUTORIALS_MAIN_WINDOW_H
#define QTUTORIALS_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>

#ifndef Q_MOC_RUN
#include "common/ui_main_window.h"
#include "qnode.hpp"
#include "arming.hpp"
#endif

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */



class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(QNode *node, QWidget *parent = 0);
	~MainWindow();

public:
    void move();


private Q_SLOTS:
    void on_Down_clicked();
    void on_Up_clicked();
    void on_Right_clicked();
    void on_Left_clicked();
    void on_Back_clicked();
    void on_Forward_clicked();
    void on_Takeoff_clicked();
    void on_Land_clicked();
    void on_ReturnHome_clicked();
    void on_Arm_clicked();
    void on_Disarm_clicked();
    void keyPressEvent(QKeyEvent *k);

private:
    Ui::MainWindowDesign ui;
    QNode *qnode;
    Arming *armDis;
};

#endif // QTUTORIALS_MAIN_WINDOW_H
