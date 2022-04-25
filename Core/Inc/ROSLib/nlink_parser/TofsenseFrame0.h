#ifndef _ROS_nlink_parser_TofsenseFrame0_h
#define _ROS_nlink_parser_TofsenseFrame0_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nlink_parser
{

  class TofsenseFrame0 : public ros::Msg
  {
    public:
      typedef uint8_t _id_type;
      _id_type id;
      typedef uint32_t _system_time_type;
      _system_time_type system_time;
      typedef float _dis_type;
      _dis_type dis;
      typedef uint8_t _dis_status_type;
      _dis_status_type dis_status;
      typedef uint16_t _signal_strength_type;
      _signal_strength_type signal_strength;
      typedef uint8_t _range_precision_type;
      _range_precision_type range_precision;

    TofsenseFrame0():
      id(0),
      system_time(0),
      dis(0),
      dis_status(0),
      signal_strength(0),
      range_precision(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->system_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->system_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->system_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->system_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->system_time);
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
      *(outbuffer + offset + 0) = (this->range_precision >> (8 * 0)) & 0xFF;
      offset += sizeof(this->range_precision);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
      this->system_time =  ((uint32_t) (*(inbuffer + offset)));
      this->system_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->system_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->system_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->system_time);
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
      this->range_precision =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->range_precision);
     return offset;
    }

    virtual const char * getType() override { return "nlink_parser/TofsenseFrame0"; };
    virtual const char * getMD5() override { return "5579723ab4876e453dd6025247ac5ffb"; };

  };

}
#endif
