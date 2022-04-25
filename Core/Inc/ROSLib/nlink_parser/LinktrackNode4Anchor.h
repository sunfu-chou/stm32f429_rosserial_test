#ifndef _ROS_nlink_parser_LinktrackNode4Anchor_h
#define _ROS_nlink_parser_LinktrackNode4Anchor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nlink_parser
{

  class LinktrackNode4Anchor : public ros::Msg
  {
    public:
      typedef uint8_t _id_type;
      _id_type id;
      typedef float _dis_type;
      _dis_type dis;

    LinktrackNode4Anchor():
      id(0),
      dis(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
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
     return offset;
    }

    virtual const char * getType() override { return "nlink_parser/LinktrackNode4Anchor"; };
    virtual const char * getMD5() override { return "3449514afa3f54cb0e542c3e3a394e77"; };

  };

}
#endif
