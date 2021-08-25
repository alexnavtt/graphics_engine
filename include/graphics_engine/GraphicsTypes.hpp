#ifndef GRAPHICS_TYPES_HPP_
#define GRAPHICS_TYPES_HPP_

#include <array>
#include <GL/glew.h>
#include <memory>

struct DisplayException : public std::exception
{
	const char * what () const throw ()
    {
    	return "Could not create an OpenGL window!";
    }
};

struct Colour{
    float& r() {return data_[0];}
    float& g() {return data_[1];}
    float& b() {return data_[2];}
    float& a() {return data_[3];}

    const float r() const {return data_[0];}
    const float g() const {return data_[1];}
    const float b() const {return data_[2];}
    const float a() const {return data_[3];}

    float* data(){return data_;}

private:
    float data_[4] = {0, 0, 0, 1};
};

struct Point2D{
    float& x() {return pos_[0];}
    float& y() {return pos_[1];}
    const float x() const {return pos_[0];}
    const float y() const {return pos_[1];}

    Colour colour;

    float* data(){
        memcpy(data_, pos_, sizeof(pos_));
        const float* c_data = colour.data();
        memcpy(data_ + 2, c_data, sizeof(c_data));
        return data_;
    }
private:
    float pos_[2];
    float data_[6];
};

struct Point3D{
    float& x() {return pos_[0];}
    float& y() {return pos_[1];}
    float& z() {return pos_[2];}
    const float x() const {return pos_[0];}
    const float y() const {return pos_[1];}
    const float z() const {return pos_[2];}

    Colour colour;

    float* data(){
        memcpy(data_, pos_, sizeof(pos_));
        const float* c_data = colour.data();
        memcpy(data_ + 2, c_data, sizeof(c_data));
        return data_;
    }

private:
    float pos_[3];
    float data_[7];
};

typedef Point2D Vec2D;
typedef Point3D Vec3D;


typedef std::shared_ptr<Point2D> PointPtr;

#endif
