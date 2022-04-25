#ifndef _ROS_nlink_parser_IotFrame0_h
#define _ROS_nlink_parser_IotFrame0_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nlink_parser/IotFrame0Node.h"

namespace nlink_parser
{

  class IotFrame0 : public ros::Msg
  {
    public:
      typedef uint32_t _uid_type;
      _uid_type uid;
      uint32_t nodes_length;
      typedef nlink_parser::IotFrame0Node _nodes_type;
      _nodes_type st_nodes;
      _nodes_type * nodes;

    IotFrame0():
      uid(0),
      nodes_length(0), st_nodes(), nodes(nullptr)
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
      this->uid =  ((uint32_t) (*(inbuffer + offset)));
      this->uid |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->uid |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->uid |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->uid);
      uint32_t nodes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->nodes_length);
      if(nodes_lengthT > nodes_length)
        this->nodes = (nlink_parser::IotFrame0Node*)realloc(this->nodes, nodes_lengthT * sizeof(nlink_parser::IotFrame0Node));
      nodes_length = nodes_lengthT;
      for( uint32_t i = 0; i < nodes_length; i++){
      offset += this->st_nodes.deserialize(inbuffer + offset);
        memcpy( &(this->nodes[i]), &(this->st_nodes), sizeof(nlink_parser::IotFrame0Node));
      }
     return offset;
    }

    virtual const char * getType() override { return "nlink_parser/IotFrame0"; };
    virtual const char * getMD5() override { return "5942449595b10adf20faeffdc7ac5270"; };

  };

}
#endif
