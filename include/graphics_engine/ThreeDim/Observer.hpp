#ifndef OBSERVER_HPP_
#define OBSERVER_HPP_

#include "graphics_engine/base/Display.hpp"
#include "graphics_engine/ThreeDim/Mesh.hpp"
#include "graphics_engine/TwoDim/Point2D.hpp"
#include "graphics_engine/TwoDim/Triangle2D.hpp"
#include "graphics_engine/ThreeDim/Triangle3D.hpp"
#include "graphics_engine/ThreeDim/Orientation.hpp"

class Observer{
public:
    /**
     * Location of the observer frame
     */
    Point3D loc;

    /**
     * Orientation of the observer frame
     */
    Orientation ori;

    /**
     * Distance from the observer to the screen
     */
    float screen_dist;

    /**
     * Project a 3D point onto the screen
     * @param p3D       A 3D point to project onto the screen
     * @return          A 2D point which can be fed to a Display for rendering
     */
    Point2D project(const Point3D& p3D);

    /**
     * Project a 3D triange onto the screen
     * @param tri3D     A 3D triangle to project onto the screen
     * @return          A 2D triangle which can be fed to a Display for rendering
     */
    Triangle2D project(const Triangle3D& tri3D);

    /**
     * Render a 3D Mesh
     */
    void drawMesh(const Mesh& mesh, const Display& disp);
};

#endif 
