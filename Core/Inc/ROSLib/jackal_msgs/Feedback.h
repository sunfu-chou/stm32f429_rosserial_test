#ifndef _ROS_jackal_msgs_Feedback_h
#define _ROS_jackal_msgs_Feedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jackal_msgs/DriveFeedback.h"

namespace jackal_msgs
{

  class Feedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      jackal_msgs::DriveFeedback drivers[2];
      typedef float _pcb_temperature_type;
      _pcb_temperature_type pcb_temperature;
      typedef float _mcu_temperature_type;
      _mcu_temperature_type mcu_temperature;
      typedef int8_t _commanded_mode_type;
      _commanded_mode_type commanded_mode;
      typedef int8_t _actual_mode_type;
      _actual_mode_type actual_mode;

    Feedback():
      header(),
      drivers(),
      pcb_temperature(0),
      mcu_temperature(0),
      commanded_mode(0),
      actual_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      offset += this->drivers[i].serialize(outbuffer + offset);
      }
      union {
        float real;
        uint32_t base;
      } u_pcb_temperature;
      u_pcb_temperature.real = this->pcb_temperature;
      *(outbuffer + offset + 0) = (u_pcb_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pcb_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pcb_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pcb_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pcb_temperature);
      union {
        float real;
        uint32_t base;
      } u_mcu_temperature;
      u_mcu_temperature.real = this->mcu_temperature;
      *(outbuffer + offset + 0) = (u_mcu_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mcu_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mcu_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mcu_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mcu_temperature);
      union {
        int8_t real;
        uint8_t base;
      } u_commanded_mode;
      u_commanded_mode.real = this->commanded_mode;
      *(outbuffer + offset + 0) = (u_commanded_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->commanded_mode);
      union {
        int8_t real;
        uint8_t base;
      } u_actual_mode;
      u_actual_mode.real = this->actual_mode;
      *(outbuffer + offset + 0) = (u_actual_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->actual_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      offset += this->drivers[i].deserialize(inbuffer + offset);
      }
      union {
        float real;
        uint32_t base;
      } u_pcb_temperature;
      u_pcb_temperature.base = 0;
      u_pcb_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pcb_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pcb_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pcb_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pcb_temperature = u_pcb_temperature.real;
      offset += sizeof(this->pcb_temperature);
      union {
        float real;
        uint32_t base;
      } u_mcu_temperature;
      u_mcu_temperature.base = 0;
      u_mcu_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mcu_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mcu_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mcu_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mcu_temperature = u_mcu_temperature.real;
      offset += sizeof(this->mcu_temperature);
      union {
        int8_t real;
        uint8_t base;
      } u_commanded_mode;
      u_commanded_mode.base = 0;
      u_commanded_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->commanded_mode = u_commanded_mode.real;
      offset += sizeof(this->commanded_mode);
      union {
        int8_t real;
        uint8_t base;
      } u_actual_mode;
      u_actual_mode.base = 0;
      u_actual_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->actual_mode = u_actual_mode.real;
      offset += sizeof(this->actual_mode);
     return offset;
    }

    virtual const char * getType() override { return "jackal_msgs/Feedback"; };
    virtual const char * getMD5() override { return "3bdabb0ef46338ee5672d1b82220ab49"; };

  };

}
#endif
