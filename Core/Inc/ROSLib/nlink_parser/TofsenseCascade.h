#ifndef _ROS_nlink_parser_TofsenseCascade_h
#define _ROS_nlink_parser_TofsenseCascade_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nlink_parser/TofsenseFrame0.h"

namespace nlink_parser
{

  class TofsenseCascade : public ros::Msg
  {
    public:
      uint32_t nodes_length;
      typedef nlink_parser::TofsenseFrame0 _nodes_type;
      _nodes_type st_nodes;
      _nodes_type * nodes;

    TofsenseCascade():
      nodes_length(0), st_nodes(), nodes(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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
      uint32_t nodes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->nodes_length);
      if(nodes_lengthT > nodes_length)
        this->nodes = (nlink_parser::TofsenseFrame0*)realloc(this->nodes, nodes_lengthT * sizeof(nlink_parser::TofsenseFrame0));
      nodes_length = nodes_lengthT;
      for( uint32_t i = 0; i < nodes_length; i++){
      offset += this->st_nodes.deserialize(inbuffer + offset);
        memcpy( &(this->nodes[i]), &(this->st_nodes), sizeof(nlink_parser::TofsenseFrame0));
      }
     return offset;
    }

    virtual const char * getType() override { return "nlink_parser/TofsenseCascade"; };
    virtual const char * getMD5() override { return "e254ff763c3396ff0c54cf33bd09b21b"; };

  };

}
#endif
