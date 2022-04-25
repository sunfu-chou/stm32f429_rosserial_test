#ifndef _ROS_nlink_parser_LinktrackAoaNode0_h
#define _ROS_nlink_parser_LinktrackAoaNode0_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nlink_parser
{

  class LinktrackAoaNode0 : public ros::Msg
  {
    public:
      typedef uint8_t _role_type;
      _role_type role;
      typedef uint8_t _id_type;
      _id_type id;
      typedef float _dis_type;
      _dis_type dis;
      typedef float _angle_type;
      _angle_type angle;
      typedef float _fp_rssi_type;
      _fp_rssi_type fp_rssi;
      typedef float _rx_rssi_type;
      _rx_rssi_type rx_rssi;

    LinktrackAoaNode0():
      role(0),
      id(0),
      dis(0),
      angle(0),
      fp_rssi(0),
      rx_rssi(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->role >> (8 * 0)) & 0xFF;
      offset += sizeof(this->role);
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
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.real = this->angle;
      *(outbuffer + offset + 0) = (u_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle);
      union {
        float real;
        uint32_t base;
      } u_fp_rssi;
      u_fp_rssi.real = this->fp_rssi;
      *(outbuffer + offset + 0) = (u_fp_rssi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fp_rssi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fp_rssi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fp_rssi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fp_rssi);
      union {
        float real;
        uint32_t base;
      } u_rx_rssi;
      u_rx_rssi.real = this->rx_rssi;
      *(outbuffer + offset + 0) = (u_rx_rssi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rx_rssi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rx_rssi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rx_rssi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rx_rssi);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->role =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->role);
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
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.base = 0;
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle = u_angle.real;
      offset += sizeof(this->angle);
      union {
        float real;
        uint32_t base;
      } u_fp_rssi;
      u_fp_rssi.base = 0;
      u_fp_rssi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fp_rssi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fp_rssi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fp_rssi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fp_rssi = u_fp_rssi.real;
      offset += sizeof(this->fp_rssi);
      union {
        float real;
        uint32_t base;
      } u_rx_rssi;
      u_rx_rssi.base = 0;
      u_rx_rssi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rx_rssi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rx_rssi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rx_rssi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rx_rssi = u_rx_rssi.real;
      offset += sizeof(this->rx_rssi);
     return offset;
    }

    virtual const char * getType() override { return "nlink_parser/LinktrackAoaNode0"; };
    virtual const char * getMD5() override { return "14ecc209e569ea4b0a93a8b73bd0cd13"; };

  };

}
#endif
