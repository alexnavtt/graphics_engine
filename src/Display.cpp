#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include "GL/gl.h"

#include <iostream>
#include <unistd.h>

#include "graphics_engine/base/Display.hpp"
#include "graphics_engine/base/Exceptions.hpp"

using std::vector;
using std::cout;
using std::endl;

Display::Display(){
    // --- Start GLFW (Window Library) --- //
    if (!glfwInit()){
        std::cout << "Whoops, didn't work" << std::endl;  
    }else{
        std::cout << "Worked!" << std::endl;
    }

	// Open a window and create its OpenGL context
	window_ = glfwCreateWindow( 1024, 768, "Graphics Engine", NULL, NULL);
    if (!window_){
        throw DisplayException();
    }
    glfwMakeContextCurrent(window_);




    // --- Start GLEW (Drawing Library) --- //
    glewInit();



    // --- Install shaders --- //

    // Load the vertex shader
    vertex_shader_id_ = glCreateShader(GL_VERTEX_SHADER);
    const char* vertex_shader_code[1] = {
    #include "graphics_engine/TwoDim/2DVertexShader"
    };
    glShaderSource(vertex_shader_id_, 1, vertex_shader_code, 0);
    glCompileShader(vertex_shader_id_);

    // Load the fragment shader
    fragment_shader_id_ = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragment_shader_code[1] = {
    #include "graphics_engine/TwoDim/2DFragmentShader"
    };
    glShaderSource(fragment_shader_id_, 1, fragment_shader_code, 0);
    glCompileShader(fragment_shader_id_);

    GLuint program_id = glCreateProgram();
    glAttachShader(program_id, vertex_shader_id_);
    glAttachShader(program_id, fragment_shader_id_);
    glLinkProgram(program_id);
    glUseProgram(program_id);

    // Check Vertex Shader
    GLint Result = GL_FALSE;
    int InfoLogLength;
	glGetShaderiv(vertex_shader_id_, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(vertex_shader_id_, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(vertex_shader_id_, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
}

void Display::close(){
    glfwDestroyWindow(window_);
}

void Display::setBackgroundColor(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
    glClear( GL_COLOR_BUFFER_BIT );
}

void Display::render(){
    glfwSwapBuffers(window_);
    glfwPollEvents();
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::drawLine(const Line& L){
    float data[] = {L.p1.x(), L.p1.y(), L.p2.x(), L.p2.y()};

    GLuint buffer_id;
    glGenBuffers(1, &buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_LINES, 0, 2);
    glDisableVertexAttribArray(0);
}

void Display::drawTriangle(Triangle2D& T) const{
    GLuint vertex_buffer;
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, T.dataSize(), T.data(), GL_STATIC_DRAW);

    // Enable vertex array
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*7, (void*)(0));

    // Enable colour array
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float)*7, (void*)(sizeof(float)*3));

    // Enable depth buffer
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(float)*7, (void*)(sizeof(float)*2));

    // Draw the triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Clear permissions so that other functions can work
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
}

void Display::drawTriangleArray(vector<Point2D>& points, const vector<GLuint>& array) const{
    if (points.empty()) return;

    // Get the point data in the right form
    vector<float> vertices;
    const uint point_elements = points[0].dataSize()/sizeof(float);
    vertices.reserve(points.size()*point_elements);
    for (Point2D& p : points){
        const float* data = p.data();
        for (int i = 0; i < point_elements; i++){
            vertices.push_back(p.data()[i]);
        }
    }
    
    GLuint vertex_buffer;
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertices.size(), vertices.data(), GL_STATIC_DRAW);

    GLuint element_buffer;
    glGenBuffers(1, &element_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*array.size(), array.data(), GL_STATIC_DRAW);

    // Enable vertex array
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*7, (void*)(0));

    // Enable colour array
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float)*7, (void*)(sizeof(float)*3));

    // Enable depth buffer
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(float)*7, (void*)(sizeof(float)*2));

    glDrawElements(GL_TRIANGLES, array.size(), GL_UNSIGNED_INT, (void*)(0));

    // Clear permissions so that other functions can work
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
}
