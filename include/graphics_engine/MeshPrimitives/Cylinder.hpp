#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

#include <math.h>
#include "graphics_engine/ThreeDim/Mesh.hpp"
#include "graphics_engine/base/Transforms.hpp"

class Cylinder : public Mesh{
public:
    Cylinder(float radius, float length, Pose3D pose, uint resolution = 20){
        points.reserve(2*resolution + 2);

        // Upper and lower center points
        points.push_back({0, 0,  0.5*length});
        points.push_back({0, 0, -0.5*length});

        // Ring points
        float d_theta = 2*M_PI/resolution;
        for (uint i = 0; i <= resolution + 1; i++){
            points.push_back({radius*cos(i*d_theta), radius*sin(i*d_theta),  0.5*length});
            points.push_back({radius*cos(i*d_theta), radius*sin(i*d_theta), -0.5*length});

            // The order of these matter
            if (i > 0){
                // Top circle
                indices.push_back(0);
                indices.push_back(2*i);
                indices.push_back(2*i + 2);

                // Bottom circle
                indices.push_back(1);
                indices.push_back(2*i + 1);
                indices.push_back(2*i + 3);

                // Top outline
                outline.push_back(2*i);
                outline.push_back(2*i + 2);

                // Bottom outine
                outline.push_back(2*i + 1);
                outline.push_back(2*i + 3);

                // Cylinder wall
                indices.push_back(2*i - 2);
                indices.push_back(2*i + 0);
                indices.push_back(2*i + 3);

                indices.push_back(2*i - 2);
                indices.push_back(2*i + 3);
                indices.push_back(2*i + 1);
            }
        }
    }

    Cylinder(float radius, float length, uint resolution = 20){
        Pose3D p;
        Cylinder(radius, length, p, resolution);
    }
};

#endif
