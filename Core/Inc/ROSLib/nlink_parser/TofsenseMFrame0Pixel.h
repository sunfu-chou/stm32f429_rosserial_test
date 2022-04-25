#ifndef _ROS_nlink_parser_TofsenseMFrame0Pixel_h
#define _ROS_nlink_parser_TofsenseMFrame0Pixel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nlink_parser
{

  class TofsenseMFrame0Pixel : public ros::Msg
  {
    public:
      typedef float _dis_type;
      _dis_type dis;
      typedef uint8_t _dis_status_type;
      _dis_status_type dis_status;
      typedef uint16_t _signal_strength_type;
      _signal_strength_type signal_strength;

    TofsenseMFrame0Pixel():
      dis(0),
      dis_status(0),
      signal_strength(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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
      *(outbuffer + offset + 0) = (this->dis_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dis_status);
      *(outbuffer + offset + 0) = (this->signal_strength >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->signal_strength >> (8 * 1)) & 0xFF;
      offset += sizeof(this->signal_strength);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
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
      this->dis_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->dis_status);
      this->signal_strength =  ((uint16_t) (*(inbuffer + offset)));
      this->signal_strength |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->signal_strength);
     return offset;
    }

    virtual const char * getType() override { return "nlink_parser/TofsenseMFrame0Pixel"; };
    virtual const char * getMD5() override { return "d8d02fd7942fc6660671b1c9411abd9c"; };

  };

}
#endif
