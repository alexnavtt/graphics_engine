#ifndef THREE_DIM_UTIL_HPP_
#define THREE_DIM_UTIL_HPP_

#include "graphics_engine/ThreeDim/Mesh.hpp"
#include "graphics_engine/base/Transforms.hpp"

static inline Pose3D transform(Pose3D p_in, Transform3D T){
    Pose3D p_out;

    p_out.ori = p_in.ori * T.rotation;
    T.rotation.rotateVector(&p_in.loc);
    p_in.loc = p_in.loc + T.translation;
}

#endif