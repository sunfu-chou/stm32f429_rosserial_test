#ifndef _ROS_nlink_parser_LinktrackNodeframe0_h
#define _ROS_nlink_parser_LinktrackNodeframe0_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nlink_parser/LinktrackNode0.h"

namespace nlink_parser
{

  class LinktrackNodeframe0 : public ros::Msg
  {
    public:
      typedef uint8_t _role_type;
      _role_type role;
      typedef uint8_t _id_type;
      _id_type id;
      uint32_t nodes_length;
      typedef nlink_parser::LinktrackNode0 _nodes_type;
      _nodes_type st_nodes;
      _nodes_type * nodes;

    LinktrackNodeframe0():
      role(0),
      id(0),
      nodes_length(0), st_nodes(), nodes(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->role >> (8 * 0)) & 0xFF;
      offset += sizeof(this->role);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->nodes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->nodes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->nodes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->nodes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nodes_length);
      for( uint32_t i = 0; i < nodes_length; i++){
      offset += this->nodes[i].serialize(outbuffer + offset);
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
      uint32_t nodes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->nodes_length);
      if(nodes_lengthT > nodes_length)
        this->nodes = (nlink_parser::LinktrackNode0*)realloc(this->nodes, nodes_lengthT * sizeof(nlink_parser::LinktrackNode0));
      nodes_length = nodes_lengthT;
      for( uint32_t i = 0; i < nodes_length; i++){
      offset += this->st_nodes.deserialize(inbuffer + offset);
        memcpy( &(this->nodes[i]), &(this->st_nodes), sizeof(nlink_parser::LinktrackNode0));
      }
     return offset;
    }

    virtual const char * getType() override { return "nlink_parser/LinktrackNodeframe0"; };
    virtual const char * getMD5() override { return "99d2eee732fdf2fb898d64e9172d0e66"; };

  };

}
#endif
