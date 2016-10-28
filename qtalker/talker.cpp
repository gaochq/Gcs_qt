/**
 * @file /qtalker/talker.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include "talker.hpp"
#include <std_msgs/String.h>
#include <sstream>
#include <std_msgs/Float64.h>
#include "std_msgs/Float64MultiArray.h"

extern double move_set[4];
/*****************************************************************************
** Implementation
*****************************************************************************/

Talker::Talker(int argc, char** argv ) :
	QNode(argc,argv,"qtalker")
{

}

void Talker::ros_comms_init()
{
    ros::NodeHandle n;
    chatter_publisher = n.advertise<std_msgs::Float64MultiArray>("chatter", 1);
}

void Talker::run()
{
    ros::Rate loop_rate(1);
    std_msgs::MultiArrayLayout msg;

    const unsigned int data_sz = 4;
    std_msgs::Float64MultiArray m;

    m.layout.dim.push_back(std_msgs::MultiArrayDimension());
    m.layout.dim[0].size = data_sz;
    m.layout.dim[0].stride = 1;
    m.layout.dim[0].label = "bla";
    // only needed if you don't want to use push_back
    m.data.resize(data_sz);


    ros::Rate naptime(0.2);
	int count = 0;
    while ( ros::ok() )
    {
        m.data[0] = move_set[0];
        m.data[1] = move_set[1];
        m.data[2] = move_set[2];

        chatter_publisher.publish(m);
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}
