#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <array>
#include <vector>
#include <memory>
#include <cstring>  // for memcpy

#include <GL/glew.h>
#include "GLFW/glfw3.h"

#include "graphics_engine/Line.hpp"
#include "graphics_engine/Traingle.hpp"


class Window{
public:
    // Constructor: Great a GL Window
    Window();

    // Close the window
    void close();

    // Draw a triangle in the window. Requires a followup call to render()
    void drawTriangle(Triangle& T);

    void drawLine(const Line& L);

    // Set the window background colour. Requires a followup call to render()
    void setBackgroundColor(float r, float g, float b, float a);

    // Apply all changes since the last render to the window
    void render();

private:
    // Pointer to the window instance
    GLFWwindow* window_;

    // ID For Shaders
    GLuint vertex_shader_id_;
    GLuint fragment_shader_id_;
};

#endif
