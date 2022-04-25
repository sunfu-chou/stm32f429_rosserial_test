#ifndef _ROS_obstacle_detector_Obstacles_h
#define _ROS_obstacle_detector_Obstacles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "obstacle_detector/SegmentObstacle.h"
#include "obstacle_detector/CircleObstacle.h"

namespace obstacle_detector
{

  class Obstacles : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t segments_length;
      typedef obstacle_detector::SegmentObstacle _segments_type;
      _segments_type st_segments;
      _segments_type * segments;
      uint32_t circles_length;
      typedef obstacle_detector::CircleObstacle _circles_type;
      _circles_type st_circles;
      _circles_type * circles;

    Obstacles():
      header(),
      segments_length(0), st_segments(), segments(nullptr),
      circles_length(0), st_circles(), circles(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->segments_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->segments_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->segments_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->segments_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->segments_length);
      for( uint32_t i = 0; i < segments_length; i++){
      offset += this->segments[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->circles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->circles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->circles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->circles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->circles_length);
      for( uint32_t i = 0; i < circles_length; i++){
      offset += this->circles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t segments_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->segments_length);
      if(segments_lengthT > segments_length)
        this->segments = (obstacle_detector::SegmentObstacle*)realloc(this->segments, segments_lengthT * sizeof(obstacle_detector::SegmentObstacle));
      segments_length = segments_lengthT;
      for( uint32_t i = 0; i < segments_length; i++){
      offset += this->st_segments.deserialize(inbuffer + offset);
        memcpy( &(this->segments[i]), &(this->st_segments), sizeof(obstacle_detector::SegmentObstacle));
      }
      uint32_t circles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      circles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      circles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      circles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->circles_length);
      if(circles_lengthT > circles_length)
        this->circles = (obstacle_detector::CircleObstacle*)realloc(this->circles, circles_lengthT * sizeof(obstacle_detector::CircleObstacle));
      circles_length = circles_lengthT;
      for( uint32_t i = 0; i < circles_length; i++){
      offset += this->st_circles.deserialize(inbuffer + offset);
        memcpy( &(this->circles[i]), &(this->st_circles), sizeof(obstacle_detector::CircleObstacle));
      }
     return offset;
    }

    virtual const char * getType() override { return "obstacle_detector/Obstacles"; };
    virtual const char * getMD5() override { return "043bbf49c7775f8111e850268dbcf2e3"; };

  };

}
#endif
