#include <iostream>
#include <unistd.h>
#include "graphics_engine/base/Display.hpp"
#include "graphics_engine/ThreeDim/Mesh.hpp"
#include "graphics_engine/ThreeDim/Observer.hpp"

int main(){
    Mesh cube;
    // Far face
    cube.triangles.push_back(Triangle3D({1, 1, 1}, {1, -1, 1}, {1, 1, -1}));
    cube.triangles.push_back(Triangle3D({1, -1, 1}, {1, -1, -1}, {1, 1, -1}));
    // Left face
    cube.triangles.push_back(Triangle3D({1, 1, 1}, {-1, 1, 1}, {-1, 1, -1}));
    cube.triangles.push_back(Triangle3D({1, 1, 1}, {-1, 1, -1}, {1, 1, -1}));
    // Right face
    cube.triangles.push_back(Triangle3D({1, -1, 1}, {-1, -1, 1}, {-1, -1, -1}));
    cube.triangles.push_back(Triangle3D({1, -1, 1}, {-1, -1, -1}, {1, -1, -1}));
    // Rear face
    cube.triangles.push_back(Triangle3D({-1, 1, 1}, {-1, -1, 1}, {-1, 1, -1}));
    cube.triangles.push_back(Triangle3D({-1, -1, 1}, {-1, -1, -1}, {-1, 1, -1}));
    // Top face 
    cube.triangles.push_back(Triangle3D({1, 1, 1}, {1, -1, 1}, {-1, -1, 1}));
    cube.triangles.push_back(Triangle3D({1, 1, 1}, {-1, -1, 1}, {-1, 1, 1}));
    // Bottom face
    cube.triangles.push_back(Triangle3D({1, 1, -1}, {1, -1, -1}, {-1, -1, -1}));
    cube.triangles.push_back(Triangle3D({1, 1, -1}, {-1, -1, -1}, {-1, 1, -1}));


    cube.triangles[0].colour.r() = 1;
    cube.triangles[1].colour.g() = 1;
    cube.triangles[2].colour.b() = 1;
    cube.triangles[3].colour.r() = 0.5;
    cube.triangles[4].colour = Colour(1, 1, 0, 1);
    cube.triangles[5].colour = Colour(1, 0, 1, 1);
    cube.triangles[6].colour = Colour(0, 1, 1, 1);
    cube.triangles[7].colour = Colour(1, 1, 1, 1);
    cube.triangles[8].colour = Colour(0.5, 0.5, 1, 1);
    cube.triangles[9].colour = Colour(0.5, 1, 0.5, 1);
    cube.triangles[10].colour = Colour(1, 0.5, 0.5, 1);
    cube.triangles[11].colour = Colour(0.5, 0.5, 0.5, 1);

    Observer obs;
    obs.screen_dist = 1;
    obs.loc = {-3, 0, -4};

    Display disp;
    disp.render();
    Triangle2D tri1 = obs.project(cube.triangles[0]);
    Triangle2D tri2 = obs.project(cube.triangles[1]);
    disp.setBackgroundColor(0, 0, 0, 0.1);
    disp.drawTriangle(tri1);
    disp.drawTriangle(tri2);
    disp.render();

    float yaw = 0;
    while(true){
        obs.loc.x() = -6*cos(yaw);
        obs.loc.z() =  6*sin(yaw);
        // obs.ori.setRPY(0, -M_PI/3, -yaw);
        obs.ori.setRPY(0, yaw, 0);

        obs.drawMesh(cube, disp);
        disp.render();

        yaw += 0.01;
        usleep(1000);
        // glfwPollEvents();
    }

    return 0;
}