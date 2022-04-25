#ifndef _ROS_nlink_parser_LinktrackNodeframe4_h
#define _ROS_nlink_parser_LinktrackNodeframe4_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nlink_parser/LinktrackNode4Tag.h"

namespace nlink_parser
{

  class LinktrackNodeframe4 : public ros::Msg
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
      uint32_t tags_length;
      typedef nlink_parser::LinktrackNode4Tag _tags_type;
      _tags_type st_tags;
      _tags_type * tags;

    LinktrackNodeframe4():
      role(0),
      id(0),
      local_time(0),
      system_time(0),
      voltage(0),
      tags_length(0), st_tags(), tags(nullptr)
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
      *(outbuffer + offset + 0) = (this->tags_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_length);
      for( uint32_t i = 0; i < tags_length; i++){
      offset += this->tags[i].serialize(outbuffer + offset);
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
      uint32_t tags_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tags_length);
      if(tags_lengthT > tags_length)
        this->tags = (nlink_parser::LinktrackNode4Tag*)realloc(this->tags, tags_lengthT * sizeof(nlink_parser::LinktrackNode4Tag));
      tags_length = tags_lengthT;
      for( uint32_t i = 0; i < tags_length; i++){
      offset += this->st_tags.deserialize(inbuffer + offset);
        memcpy( &(this->tags[i]), &(this->st_tags), sizeof(nlink_parser::LinktrackNode4Tag));
      }
     return offset;
    }

    virtual const char * getType() override { return "nlink_parser/LinktrackNodeframe4"; };
    virtual const char * getMD5() override { return "f3127a55ee0f30a49a0427a969f1b3ee"; };

  };

}
#endif
