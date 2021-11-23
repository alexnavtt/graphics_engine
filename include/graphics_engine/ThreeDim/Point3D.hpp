#ifndef POINT_3D_HPP_
#define POINT_3D_HPP_

#include <math.h>
#include <iostream>
#include "graphics_engine/base/Point.hpp"

class Vec3D;

/**
 * Point in 3D space
 */
class Point3D : public Point{
public:
    /**
     * Default constructor: constructs point at (0, 0, 0)
     */
    Point3D(){}

    /**
     * Construct point using a 3 element coordinate
     */
    Point3D(float x, float y, float z){
        this->x() = x;
        this->y() = y;
        this->z() = z;
    }

    /**
     * Access Point z element
     */ 
    float& z(){return data_[2];} const float& z() const {return data_[2];}

    /**
     * Get the squared norm of the position vector
     */
    float sqNorm(){return data_[0]*data_[0] + data_[1]*data_[1];}

    /**
     * Get the 2-norm of the position vector
     */ 
    float norm(){return sqrt(sqNorm());}

    // --- Operator Overloads --- //

    /**
     * Add a vector to a point to get another point
     */
    Point3D operator +(const Vec3D& v)const;

    /**
     * Subtract two points to get a vector
     */
    Vec3D operator -(const Point3D& p)const;

    /**
     * Subtract a vector from a point
     */
    Point3D operator -(const Vec3D& v)const;

    /**
     * Print the location of the point in the console
     */
    void print(){std::cout << "(" << x() << ", " << y() << ", " << z() << ")" << std::endl;}
};

/**
 * Vector through 3D space
 */
class Vec3D : public Point3D{
public:
    /**
     * Constructor
     */
    Vec3D() : Point3D() {}
    Vec3D(float x, float y, float z) : Point3D(x, y, z) {}

    /**
     * Add a vector to a point to get another point
     */
    Point3D operator +(const Point3D& p) const{
        Point3D out;
        out.x() = p.x() + x();
        out.y() = p.y() + y();
        out.z() = p.z() + z();
        return out;
    }

    /**
     * Return the vector sum between two vectors
     */
    Vec3D operator +(const Vec3D& v) const{
        Vec3D out;
        out.x() = v.x() + x();
        out.y() = v.y() + y();
        out.z() = v.z() + z();
        return out;
    }

    /**
     * Scale a vector by a constant
     */
    Vec3D operator *(const float k) const{
        Vec3D out;
        out.x() = k*x();
        out.y() = k*y();
        out.z() = k*z();
        return out;
    }

    /**
     * Return the vector difference between two vectors
     */
    Vec3D operator -(const Vec3D& v){
        return (v*-1.0f) + (*this);
    }
};

static inline Vec3D operator*(float k, const Vec3D v_in){
    return v_in*k;
}

#endif
