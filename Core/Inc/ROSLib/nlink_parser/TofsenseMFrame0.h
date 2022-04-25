#ifndef _ROS_nlink_parser_TofsenseMFrame0_h
#define _ROS_nlink_parser_TofsenseMFrame0_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nlink_parser/TofsenseMFrame0Pixel.h"

namespace nlink_parser
{

  class TofsenseMFrame0 : public ros::Msg
  {
    public:
      typedef uint8_t _id_type;
      _id_type id;
      typedef uint32_t _system_time_type;
      _system_time_type system_time;
      typedef uint8_t _pixel_count_type;
      _pixel_count_type pixel_count;
      uint32_t pixels_length;
      typedef nlink_parser::TofsenseMFrame0Pixel _pixels_type;
      _pixels_type st_pixels;
      _pixels_type * pixels;

    TofsenseMFrame0():
      id(0),
      system_time(0),
      pixel_count(0),
      pixels_length(0), st_pixels(), pixels(nullptr)
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
      *(outbuffer + offset + 0) = (this->pixel_count >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pixel_count);
      *(outbuffer + offset + 0) = (this->pixels_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pixels_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pixels_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pixels_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pixels_length);
      for( uint32_t i = 0; i < pixels_length; i++){
      offset += this->pixels[i].serialize(outbuffer + offset);
      }
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
      this->pixel_count =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pixel_count);
      uint32_t pixels_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pixels_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pixels_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pixels_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pixels_length);
      if(pixels_lengthT > pixels_length)
        this->pixels = (nlink_parser::TofsenseMFrame0Pixel*)realloc(this->pixels, pixels_lengthT * sizeof(nlink_parser::TofsenseMFrame0Pixel));
      pixels_length = pixels_lengthT;
      for( uint32_t i = 0; i < pixels_length; i++){
      offset += this->st_pixels.deserialize(inbuffer + offset);
        memcpy( &(this->pixels[i]), &(this->st_pixels), sizeof(nlink_parser::TofsenseMFrame0Pixel));
      }
     return offset;
    }

    virtual const char * getType() override { return "nlink_parser/TofsenseMFrame0"; };
    virtual const char * getMD5() override { return "8b49d724777a20439f181e513a9f9e83"; };

  };

}
#endif
