#ifndef _ROS_nlink_parser_LinktrackTagframe0_h
#define _ROS_nlink_parser_LinktrackTagframe0_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nlink_parser
{

  class LinktrackTagframe0 : public ros::Msg
  {
    public:
      typedef uint8_t _role_type;
      _role_type role;
      typedef uint8_t _id_type;
      _id_type id;
      typedef uint32_t _local_time_type;
      _local_time_type local_time;
      typedef uint32_t _system_time_type;
      _system_time_type system_time;
      typedef float _voltage_type;
      _voltage_type voltage;
      float pos_3d[3];
      float eop_3d[3];
      float vel_3d[3];
      float dis_arr[8];
      float angle_3d[3];
      float quaternion[4];
      float imu_gyro_3d[3];
      float imu_acc_3d[3];

    LinktrackTagframe0():
      role(0),
      id(0),
      local_time(0),
      system_time(0),
      voltage(0),
      pos_3d(),
      eop_3d(),
      vel_3d(),
      dis_arr(),
      angle_3d(),
      quaternion(),
      imu_gyro_3d(),
      imu_acc_3d()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->role >> (8 * 0)) & 0xFF;
      offset += sizeof(this->role);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->local_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->local_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->local_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->local_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->local_time);
      *(outbuffer + offset + 0) = (this->system_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->system_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->system_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->system_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->system_time);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_3di;
      u_pos_3di.real = this->pos_3d[i];
      *(outbuffer + offset + 0) = (u_pos_3di.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_3di.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_3di.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_3di.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_3d[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_eop_3di;
      u_eop_3di.real = this->eop_3d[i];
      *(outbuffer + offset + 0) = (u_eop_3di.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eop_3di.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eop_3di.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eop_3di.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->eop_3d[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_vel_3di;
      u_vel_3di.real = this->vel_3d[i];
      *(outbuffer + offset + 0) = (u_vel_3di.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vel_3di.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vel_3di.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vel_3di.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel_3d[i]);
      }
      for( uint32_t i = 0; i < 8; i++){
      union {
        float real;
        uint32_t base;
      } u_dis_arri;
      u_dis_arri.real = this->dis_arr[i];
      *(outbuffer + offset + 0) = (u_dis_arri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dis_arri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dis_arri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dis_arri.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dis_arr[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_angle_3di;
      u_angle_3di.real = this->angle_3d[i];
      *(outbuffer + offset + 0) = (u_angle_3di.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_3di.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_3di.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_3di.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_3d[i]);
      }
      for( uint32_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_quaternioni;
      u_quaternioni.real = this->quaternion[i];
      *(outbuffer + offset + 0) = (u_quaternioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_quaternioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_quaternioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_quaternioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->quaternion[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_imu_gyro_3di;
      u_imu_gyro_3di.real = this->imu_gyro_3d[i];
      *(outbuffer + offset + 0) = (u_imu_gyro_3di.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_gyro_3di.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_imu_gyro_3di.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_imu_gyro_3di.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imu_gyro_3d[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_imu_acc_3di;
      u_imu_acc_3di.real = this->imu_acc_3d[i];
      *(outbuffer + offset + 0) = (u_imu_acc_3di.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_acc_3di.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_imu_acc_3di.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_imu_acc_3di.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imu_acc_3d[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->role =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->role);
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
      this->local_time =  ((uint32_t) (*(inbuffer + offset)));
      this->local_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->local_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->local_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->local_time);
      this->system_time =  ((uint32_t) (*(inbuffer + offset)));
      this->system_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->system_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->system_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->system_time);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_3di;
      u_pos_3di.base = 0;
      u_pos_3di.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pos_3di.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pos_3di.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pos_3di.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pos_3d[i] = u_pos_3di.real;
      offset += sizeof(this->pos_3d[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_eop_3di;
      u_eop_3di.base = 0;
      u_eop_3di.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eop_3di.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eop_3di.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eop_3di.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->eop_3d[i] = u_eop_3di.real;
      offset += sizeof(this->eop_3d[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_vel_3di;
      u_vel_3di.base = 0;
      u_vel_3di.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vel_3di.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vel_3di.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vel_3di.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vel_3d[i] = u_vel_3di.real;
      offset += sizeof(this->vel_3d[i]);
      }
      for( uint32_t i = 0; i < 8; i++){
      union {
        float real;
        uint32_t base;
      } u_dis_arri;
      u_dis_arri.base = 0;
      u_dis_arri.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dis_arri.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dis_arri.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dis_arri.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dis_arr[i] = u_dis_arri.real;
      offset += sizeof(this->dis_arr[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_angle_3di;
      u_angle_3di.base = 0;
      u_angle_3di.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_3di.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_3di.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_3di.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_3d[i] = u_angle_3di.real;
      offset += sizeof(this->angle_3d[i]);
      }
      for( uint32_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_quaternioni;
      u_quaternioni.base = 0;
      u_quaternioni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_quaternioni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_quaternioni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_quaternioni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->quaternion[i] = u_quaternioni.real;
      offset += sizeof(this->quaternion[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_imu_gyro_3di;
      u_imu_gyro_3di.base = 0;
      u_imu_gyro_3di.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_gyro_3di.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_imu_gyro_3di.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_imu_gyro_3di.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->imu_gyro_3d[i] = u_imu_gyro_3di.real;
      offset += sizeof(this->imu_gyro_3d[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_imu_acc_3di;
      u_imu_acc_3di.base = 0;
      u_imu_acc_3di.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_acc_3di.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_imu_acc_3di.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_imu_acc_3di.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->imu_acc_3d[i] = u_imu_acc_3di.real;
      offset += sizeof(this->imu_acc_3d[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "nlink_parser/LinktrackTagframe0"; };
    virtual const char * getMD5() override { return "20cc09884b3e1aa830a1d8a71796a857"; };

  };

}
#endif
