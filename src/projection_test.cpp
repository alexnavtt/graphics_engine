#include <iostream>
#include <unistd.h>
#include "graphics_engine/base/Display.hpp"
#include "graphics_engine/ThreeDim/Mesh.hpp"
#include "graphics_engine/ThreeDim/Observer.hpp"
#include "graphics_engine/MeshPrimitives/Axis.hpp"
#include "graphics_engine/MeshPrimitives/Cube.hpp"
#include "graphics_engine/MeshPrimitives/Cylinder.hpp"

int main(){
    // Cube cube(2, {0, 0, 0});
    Cylinder cube(1, 2, Pose3D(), 100);
    cube.draw_outline = true;
    cube.shade_faces  = true;

    Axis ax(Point3D(0, 1, 0));

    int i = 0;
    for (Point3D &p : cube.points){
        p.setColour({i%3, (i+1)%3, (i+2)%3, 1});
        i++;
    }

    Observer obs;
    obs.screen_dist = 1;
    obs.loc = {-3, 0, -4};

    Display disp;
    disp.setBackgroundColor(0.5, 0.5, 0.5, 1);
    disp.render();

    std::vector<Point2D> elements;
    elements.push_back(Point2D(0, 0));
    elements.push_back(Point2D(1, 0));
    elements.push_back(Point2D(0.5, 1));
    std::vector<GLuint> indices({0, 1, 2});
    disp.drawTriangleArray(elements, indices);
    disp.render();

    float yaw = 0;
    while(true){
        obs.loc.x() = -6*cos(yaw);
        obs.loc.z() =  6*sin(yaw);
        // obs.ori.setRPY(0, -M_PI/3, -yaw);
        obs.ori.setRPY(0, yaw, 0);

        obs.drawMesh(cube, disp);
        obs.drawMesh(ax, disp);
        disp.render();

        yaw += 0.01;
        // usleep(1000);
        // glfwPollEvents();
    }

    // while (true){
    //     glfwPollEvents();
    // }

    return 0;
}