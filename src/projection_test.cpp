#include <iostream>
#include <unistd.h>
#include "graphics_engine/base/Display.hpp"
#include "graphics_engine/ThreeDim/Mesh.hpp"
#include "graphics_engine/ThreeDim/Observer.hpp"
#include "graphics_engine/MeshPrimitives/Cube.hpp"

int main(){
    // Mesh cube;
    // // Far face
    // cube.triangles.push_back(Triangle3D({1, 1, 1}, {1, -1, 1}, {1, 1, -1}));
    // cube.triangles.push_back(Triangle3D({1, -1, 1}, {1, -1, -1}, {1, 1, -1}));
    // // Left face
    // cube.triangles.push_back(Triangle3D({1, 1, 1}, {-1, 1, 1}, {-1, 1, -1}));
    // cube.triangles.push_back(Triangle3D({1, 1, 1}, {-1, 1, -1}, {1, 1, -1}));
    // // Right face
    // cube.triangles.push_back(Triangle3D({1, -1, 1}, {-1, -1, 1}, {-1, -1, -1}));
    // cube.triangles.push_back(Triangle3D({1, -1, 1}, {-1, -1, -1}, {1, -1, -1}));
    // // Rear face
    // cube.triangles.push_back(Triangle3D({-1, 1, 1}, {-1, -1, 1}, {-1, 1, -1}));
    // cube.triangles.push_back(Triangle3D({-1, -1, 1}, {-1, -1, -1}, {-1, 1, -1}));
    // // Top face 
    // cube.triangles.push_back(Triangle3D({1, 1, 1}, {1, -1, 1}, {-1, -1, 1}));
    // cube.triangles.push_back(Triangle3D({1, 1, 1}, {-1, -1, 1}, {-1, 1, 1}));
    // // Bottom face
    // cube.triangles.push_back(Triangle3D({1, 1, -1}, {1, -1, -1}, {-1, -1, -1}));
    // cube.triangles.push_back(Triangle3D({1, 1, -1}, {-1, -1, -1}, {-1, 1, -1}));

    // cube.triangles[0].colour.r() = 1;
    // cube.triangles[1].colour.g() = 1;
    // cube.triangles[2].colour.b() = 1;
    // cube.triangles[3].colour.r() = 0.5;
    // cube.triangles[4].colour = Colour(1, 1, 0, 1);
    // cube.triangles[5].colour = Colour(1, 0, 1, 1);
    // cube.triangles[6].colour = Colour(0, 1, 1, 1);
    // cube.triangles[7].colour = Colour(1, 1, 1, 1);
    // cube.triangles[8].colour = Colour(0.5, 0.5, 1, 1);
    // cube.triangles[9].colour = Colour(0.5, 1, 0.5, 1);
    // cube.triangles[10].colour = Colour(1, 0.5, 0.5, 1);
    // cube.triangles[11].colour = Colour(0.5, 0.5, 0.5, 1);

    // cube.points.push_back({ 1,  1, 1});
    // cube.points.push_back({-1,  1, 1});
    // cube.points.push_back({-1, -1, 1});
    // cube.points.push_back({ 1, -1, 1});
    // cube.points.push_back({ 1,  1, -1});
    // cube.points.push_back({-1,  1, -1});
    // cube.points.push_back({-1, -1, -1});
    // cube.points.push_back({ 1, -1, -1});

    // cube.indices = {0, 1, 3,   1, 2, 3,   0, 3, 7,   3, 7, 4, 
    //                 5, 4, 7,   7, 6, 5,   1, 5, 6,   6, 2, 1,
    //                 0, 4, 1,   4, 5, 1,   2, 3, 7,   7, 6, 2};
    // cube.use_element_array = true;
    Cube cube(2, {0, 0, 0});

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