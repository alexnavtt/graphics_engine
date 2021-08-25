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
    #include "graphics_engine/2DVertexShader"
    };
    glShaderSource(vertex_shader_id_, 1, vertex_shader_code, 0);
    glCompileShader(vertex_shader_id_);

    // Load the fragment shader
    fragment_shader_id_ = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragment_shader_code[1] = {
    #include "graphics_engine/2DFragmentShader"
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

void Window::drawLine(const Line& L){
    float data[] = {L.p1.x, L.p1.y, L.p2.x, L.p2.y};

    GLuint buffer_id;
    glGenBuffers(1, &buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_LINES, 0, 2);
    glDisableVertexAttribArray(0);
}

void Window::drawTriangle(Triangle& T){
    GLuint vertex_buffer;
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(T.vertices), T.vertices, GL_STATIC_DRAW);

    // Enable vertex array
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*6, (void*)(0));

    // Enable colour array
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float)*6, (void*)(sizeof(float)*2));

    glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
    // glDisableVertexAttribArray(0);
    // glDisableVertexAttribArray(1);
}

int main(){
    Window win;
    win.setBackgroundColor(0.4, 0.0, 0.4, 0.0);
    win.render();
    usleep(1000000);
    
    Triangle tri(0.0, -0.9, 0.9, 0.9, -0.9, 0.9);
    win.drawTriangle(tri);
    Line L{0, 0, 0.5, 0.5};
    // win.drawLine(L);
    win.render();
    usleep(1000000);
    
    win.close();
    usleep(1000000);
    
    glfwTerminate();
    return 0;
}