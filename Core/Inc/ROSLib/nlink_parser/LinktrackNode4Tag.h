#ifndef _ROS_nlink_parser_LinktrackNode4Tag_h
#define _ROS_nlink_parser_LinktrackNode4Tag_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nlink_parser/LinktrackNode4Anchor.h"

namespace nlink_parser
{

  class LinktrackNode4Tag : public ros::Msg
  {
    public:
      typedef uint8_t _id_type;
      _id_type id;
      typedef float _voltage_type;
      _voltage_type voltage;
      uint32_t anchors_length;
      typedef nlink_parser::LinktrackNode4Anchor _anchors_type;
      _anchors_type st_anchors;
      _anchors_type * anchors;

    LinktrackNode4Tag():
      id(0),
      voltage(0),
      anchors_length(0), st_anchors(), anchors(nullptr)
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
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage);
      *(outbuffer + offset + 0) = (this->anchors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->anchors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->anchors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->anchors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->anchors_length);
      for( uint32_t i = 0; i < anchors_length; i++){
      offset += this->anchors[i].serialize(outbuffer + offset);
      }
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
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      uint32_t anchors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      anchors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      anchors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      anchors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->anchors_length);
      if(anchors_lengthT > anchors_length)
        this->anchors = (nlink_parser::LinktrackNode4Anchor*)realloc(this->anchors, anchors_lengthT * sizeof(nlink_parser::LinktrackNode4Anchor));
      anchors_length = anchors_lengthT;
      for( uint32_t i = 0; i < anchors_length; i++){
      offset += this->st_anchors.deserialize(inbuffer + offset);
        memcpy( &(this->anchors[i]), &(this->st_anchors), sizeof(nlink_parser::LinktrackNode4Anchor));
      }
     return offset;
    }

    virtual const char * getType() override { return "nlink_parser/LinktrackNode4Tag"; };
    virtual const char * getMD5() override { return "52d7d856087ab9caa357ff4bd2e80950"; };

  };

}
#endif
