#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <array>
#include <vector>
#include <memory>
#include <cstring>  // for memcpy

#include <GL/glew.h>
#include "GLFW/glfw3.h"

#include "graphics_engine/TwoDim/Line.hpp"
#include "graphics_engine/TwoDim/Triangle2D.hpp"

class Display{
public:
    // Constructor: Great a GL Window
    Display();

    // Close the window
    void close();

    // Draw a triangle in the window. Requires a followup call to render()
    void drawTriangle(Triangle2D& T) const;

    void drawLine(const Line& L);

    void drawTriangleArray(const std::vector<Point2D>& points, const std::vector<GLuint>& array) const;

    void drawLineArray(const std::vector<Point2D>& points, const std::vector<GLuint>& array, const Colour* colour = NULL) const;

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
