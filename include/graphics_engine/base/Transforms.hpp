#ifndef TRANSFORMS_HPP_
#define TRANSFORMS_HPP_

#include "graphics_engine/TwoDim/Point2D.hpp"
#include "graphics_engine/ThreeDim/Point3D.hpp"
#include "graphics_engine/ThreeDim/Orientation.hpp"

struct Transform3D{
    Point3D translation;
    Orientation rotation;
};

struct Pose3D{
    Point3D loc;
    Orientation ori;  
};

struct Transform2D{
    Vec2D translation;
    float rotation;
};

struct Pose2D{
    Point2D loc;
    float angle;
};

#endif
