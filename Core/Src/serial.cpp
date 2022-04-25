/**
 * 
 * @file serial.cpp
 * @brief 
 * 
 * @code{.unparsed}
 *      _____
 *     /  /::\       ___           ___
 *    /  /:/\:\     /  /\         /  /\
 *   /  /:/  \:\   /  /:/        /  /:/
 *  /__/:/ \__\:| /__/::\       /  /:/
 *  \  \:\ /  /:/ \__\/\:\__   /  /::\
 *   \  \:\  /:/     \  \:\/\ /__/:/\:\
 *    \  \:\/:/       \__\::/ \__\/  \:\
 *     \  \::/        /__/:/       \  \:\
 *      \__\/         \__\/         \__\/
 * @endcode
 * 
 * @author sunfu.chou (sunfu.chou@gmail.com)
 * @version 0.1
 * @date 2022-04-24
 * 
 */

#include "serial.h"

ros::NodeHandle nh;

geometry_msgs::Twist odom_vel;
geometry_msgs::Twist cmd_vel;

ros::Publisher pub_twist("odom_vel", &odom_vel);
ros::Subscriber<geometry_msgs::Twist> sub_twist("cmd_vel", Cmd_Vel_Callback);


void Cmd_Vel_Callback(const geometry_msgs::Twist& data)
{
  memset(&cmd_vel, 0, sizeof(cmd_vel));
  memcpy(&cmd_vel, &data, sizeof(cmd_vel));
}

void Rosserial_Init(void)
{
  nh.initNode();
  nh.advertise(pub_twist);
  nh.subscribe(sub_twist);
}

void Rosserial_Task()
{
  pub_twist.publish(&odom_vel);
}
