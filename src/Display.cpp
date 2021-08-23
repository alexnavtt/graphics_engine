#include "graphics_engine/Display.hpp"
#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include "GL/gl.h"
#include <iostream>
#include <unistd.h>

using std::vector;
using std::cout;
using std::endl;

Window::Window(){
    if (!glfwInit()){
        std::cout << "Whoops, didn't work" << std::endl;  
    }else{
        std::cout << "Worked!" << std::endl;
    }

	// Open a window and create its OpenGL context
	window_ = glfwCreateWindow( 1024, 768, "Graphics Engine", NULL, NULL);
    glfwMakeContextCurrent(window_);

    glewInit();
 
    // vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    // glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    // glCompileShader(vertex_shader);
 
    // fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    // glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    // glCompileShader(fragment_shader);
}

void Window::close(){
    glfwDestroyWindow(window_);
}

void Window::setBackgroundColor(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
    glClear( GL_COLOR_BUFFER_BIT );
}

void Window::render(){
    glfwSwapBuffers(window_);
    glfwPollEvents();
    glClear( GL_COLOR_BUFFER_BIT );
}

void Window::drawTriangle(Triangle& T){
    GLuint vertex_buffer;
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(T.vertices), T.vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
}

int main(){
    Window win;
    win.setBackgroundColor(0.4, 0.0, 0.4, 0.0);
    win.render();
    usleep(1000000);
    
    Triangle tri{{0.0, -0.9, 0.0, 0.9, 0.9, 0.0, -0.9, 0.9, 0.0}};
    win.drawTriangle(tri);
    win.render();
    usleep(1000000);
    
    win.close();
    usleep(1000000);
    
    glfwTerminate();
    return 0;
}