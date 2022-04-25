#ifndef _ROS_nlink_parser_LinktrackNode1_h
#define _ROS_nlink_parser_LinktrackNode1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nlink_parser
{

  class LinktrackNode1 : public ros::Msg
  {
    public:
      typedef uint8_t _role_type;
      _role_type role;
      typedef uint8_t _id_type;
      _id_type id;
      float pos_3d[3];

    LinktrackNode1():
      role(0),
      id(0),
      pos_3d()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->role >> (8 * 0)) & 0xFF;
      offset += sizeof(this->role);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->role =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->role);
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
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
     return offset;
    }

    virtual const char * getType() override { return "nlink_parser/LinktrackNode1"; };
    virtual const char * getMD5() override { return "d132fffb83ae82e5909718b6a85eaccc"; };

  };

}
#endif
