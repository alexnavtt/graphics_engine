#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <array>
#include <vector>
#include <memory>
#include <cstring>  // for memcpy

#include <GL/glew.h>
#include "GLFW/glfw3.h"

typedef std::array<GLfloat,3> Point;
typedef std::array<GLfloat,3> Vec;

struct Triangle{
    // Triangle(std::vector<GLfloat>& verts){
    //     memcpy(vertices, verts.data(), sizeof(verts.data()));
    // }

    GLfloat vertices[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Vec normal;
};

class Window{
public:
    Window();

    void close();

    void drawTriangle(Triangle& T);

    void setBackgroundColor(float r, float g, float b, float a);

    void render();
private:
    GLFWwindow* window_;
};

#endif
