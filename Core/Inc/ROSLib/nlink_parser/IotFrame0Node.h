#ifndef _ROS_nlink_parser_IotFrame0Node_h
#define _ROS_nlink_parser_IotFrame0Node_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nlink_parser
{

  class IotFrame0Node : public ros::Msg
  {
    public:
      typedef uint32_t _uid_type;
      _uid_type uid;
      typedef uint8_t _cnt_type;
      _cnt_type cnt;
      typedef float _dis_type;
      _dis_type dis;
      typedef float _aoa_angle_horizontal_type;
      _aoa_angle_horizontal_type aoa_angle_horizontal;
      typedef float _aoa_angle_vertical_type;
      _aoa_angle_vertical_type aoa_angle_vertical;

    IotFrame0Node():
      uid(0),
      cnt(0),
      dis(0),
      aoa_angle_horizontal(0),
      aoa_angle_vertical(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->uid >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uid >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->uid >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->uid >> (8 * 3)) & 0xFF;
      offset += sizeof(this->uid);
      *(outbuffer + offset + 0) = (this->cnt >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cnt);
      union {
        float real;
        uint32_t base;
      } u_dis;
      u_dis.real = this->dis;
      *(outbuffer + offset + 0) = (u_dis.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dis.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dis.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dis.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dis);
      union {
        float real;
        uint32_t base;
      } u_aoa_angle_horizontal;
      u_aoa_angle_horizontal.real = this->aoa_angle_horizontal;
      *(outbuffer + offset + 0) = (u_aoa_angle_horizontal.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_aoa_angle_horizontal.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_aoa_angle_horizontal.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_aoa_angle_horizontal.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->aoa_angle_horizontal);
      union {
        float real;
        uint32_t base;
      } u_aoa_angle_vertical;
      u_aoa_angle_vertical.real = this->aoa_angle_vertical;
      *(outbuffer + offset + 0) = (u_aoa_angle_vertical.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_aoa_angle_vertical.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_aoa_angle_vertical.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_aoa_angle_vertical.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->aoa_angle_vertical);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->uid =  ((uint32_t) (*(inbuffer + offset)));
      this->uid |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->uid |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->uid |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->uid);
      this->cnt =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->cnt);
      union {
        float real;
        uint32_t base;
      } u_dis;
      u_dis.base = 0;
      u_dis.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dis.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dis.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dis.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dis = u_dis.real;
      offset += sizeof(this->dis);
      union {
        float real;
        uint32_t base;
      } u_aoa_angle_horizontal;
      u_aoa_angle_horizontal.base = 0;
      u_aoa_angle_horizontal.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_aoa_angle_horizontal.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_aoa_angle_horizontal.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_aoa_angle_horizontal.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->aoa_angle_horizontal = u_aoa_angle_horizontal.real;
      offset += sizeof(this->aoa_angle_horizontal);
      union {
        float real;
        uint32_t base;
      } u_aoa_angle_vertical;
      u_aoa_angle_vertical.base = 0;
      u_aoa_angle_vertical.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_aoa_angle_vertical.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_aoa_angle_vertical.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_aoa_angle_vertical.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->aoa_angle_vertical = u_aoa_angle_vertical.real;
      offset += sizeof(this->aoa_angle_vertical);
     return offset;
    }

    virtual const char * getType() override { return "nlink_parser/IotFrame0Node"; };
    virtual const char * getMD5() override { return "18c74fd1a18895f584bf54c3563d0a60"; };

  };

}
#endif
