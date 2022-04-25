/**
 * 
 * @file serial.h
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

#ifndef INC_SERIAL_H_
#define INC_SERIAL_H_

#include "ros.h"
#include "geometry_msgs/Twist.h"  

extern ros::NodeHandle nh;

extern geometry_msgs::Twist odom_vel;
extern geometry_msgs::Twist cmd_vel;

extern ros::Publisher pub_twist;
extern ros::Subscriber<geometry_msgs::Twist> sub_twist;

void Cmd_Vel_Callback(const geometry_msgs::Twist& data);
void Rosserial_Init(void);
void Rosserial_Task(double, double, double);


#endif /* INC_SERIAL_H_ */
