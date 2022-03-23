//
// Created by user on 2022/3/23.
//

#ifndef PCL_DATA_CONVERT_POINT_TYPES_H
#define PCL_DATA_CONVERT_POINT_TYPES_H

#include <pcl/point_types.h>

struct PointXYZITRL {
    PCL_ADD_POINT4D;
    std::uint8_t intensity;
    double timestamp;
    std::uint16_t ring;              ///< laser ring number
    std::uint16_t label;
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW  // make sure our new allocators are aligned
} EIGEN_ALIGN16;
// enforce SSE padding for correct memory alignment

POINT_CLOUD_REGISTER_POINT_STRUCT(PointXYZITRL,
                                  (float, x, x)(float, y,y)(float, z,z)(std::uint8_t, intensity,intensity)
                                          (double,
                                           timestamp, timestamp)
                                                  (std::uint16_t, ring, ring)
                                                  (std::uint16_t,
                                                           label, label))


#endif//PCL_DATA_CONVERT_POINT_TYPES_H
