#ifndef GRAPHICS_TYPES_HPP_
#define GRAPHICS_TYPES_HPP_

#include <array>
#include <GL/glew.h>
#include <memory>

// typedef std::array<GLfloat,3> Point;
typedef std::array<GLfloat,3> Vec;

struct DisplayException : public std::exception
{
	const char * what () const throw ()
    {
    	return "Could not create an OpenGL window!";
    }
};

struct Colour{
    float r = 1;
    float g = 0;
    float b = 0;
    float a = 1;

    float* data(){
        data_[0] = r;
        data_[1] = g;
        data_[2] = b;
        data_[3] = a;

        return data_;
    }

private:
    float data_[4];
};

struct Point{
    float x;
    float y;
    Colour colour;

    float* data(){
        data_[0] = x;
        data_[1] = y;
        const float* c_data = colour.data();
        memcpy(data_ + 2, c_data, sizeof(c_data));
        return data_;
    }
private:
    float data_[6];
};

typedef std::shared_ptr<Point> PointPtr;

#endif
