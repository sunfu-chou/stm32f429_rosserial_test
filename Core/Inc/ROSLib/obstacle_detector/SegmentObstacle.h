#ifndef _ROS_obstacle_detector_SegmentObstacle_h
#define _ROS_obstacle_detector_SegmentObstacle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace obstacle_detector
{

  class SegmentObstacle : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _first_point_type;
      _first_point_type first_point;
      typedef geometry_msgs::Point _last_point_type;
      _last_point_type last_point;

    SegmentObstacle():
      first_point(),
      last_point()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->first_point.serialize(outbuffer + offset);
      offset += this->last_point.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->first_point.deserialize(inbuffer + offset);
      offset += this->last_point.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "obstacle_detector/SegmentObstacle"; };
    virtual const char * getMD5() override { return "37ecbf7e1053bae89f0770466b37c3c3"; };

  };

}
#endif
