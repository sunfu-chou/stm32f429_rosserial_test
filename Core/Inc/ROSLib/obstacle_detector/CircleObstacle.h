#ifndef _ROS_obstacle_detector_CircleObstacle_h
#define _ROS_obstacle_detector_CircleObstacle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Vector3.h"

namespace obstacle_detector
{

  class CircleObstacle : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _center_type;
      _center_type center;
      typedef geometry_msgs::Vector3 _velocity_type;
      _velocity_type velocity;
      typedef double _radius_type;
      _radius_type radius;
      typedef double _true_radius_type;
      _true_radius_type true_radius;

    CircleObstacle():
      center(),
      velocity(),
      radius(0),
      true_radius(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->center.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_radius;
      u_radius.real = this->radius;
      *(outbuffer + offset + 0) = (u_radius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radius.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_radius.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_radius.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_radius.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_radius.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->radius);
      union {
        double real;
        uint64_t base;
      } u_true_radius;
      u_true_radius.real = this->true_radius;
      *(outbuffer + offset + 0) = (u_true_radius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_true_radius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_true_radius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_true_radius.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_true_radius.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_true_radius.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_true_radius.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_true_radius.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->true_radius);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->center.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_radius;
      u_radius.base = 0;
      u_radius.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radius.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radius.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radius.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_radius.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_radius.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_radius.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_radius.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->radius = u_radius.real;
      offset += sizeof(this->radius);
      union {
        double real;
        uint64_t base;
      } u_true_radius;
      u_true_radius.base = 0;
      u_true_radius.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_true_radius.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_true_radius.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_true_radius.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_true_radius.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_true_radius.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_true_radius.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_true_radius.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->true_radius = u_true_radius.real;
      offset += sizeof(this->true_radius);
     return offset;
    }

    virtual const char * getType() override { return "obstacle_detector/CircleObstacle"; };
    virtual const char * getMD5() override { return "d23cb7e768ed09971078d4cccc3808a9"; };

  };

}
#endif
