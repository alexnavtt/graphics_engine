#ifndef ORIENTATION_HPP_
#define ORIENTATION_HPP_

#include <math.h>
#include <iostream>
#include "graphics_engine/GraphicsTypes.hpp"

struct Orientation{
public:
    Orientation(){}

    Orientation(float w, float x, float y, float z){
        data_[0] = w;
        data_[1] = x;
        data_[2] = y;
        data_[3] = z;
    }

    float& w(){return data_[0];}
    float& x(){return data_[1];}
    float& y(){return data_[2];}
    float& z(){return data_[3];}
    const float& w() const {return data_[0];}
    const float& x() const {return data_[1];}
    const float& y() const {return data_[2];}
    const float& z() const {return data_[3];}

    Orientation operator*(const Orientation& q2){
        const Orientation& q1 = *this;
        Orientation q3;
        q3.w() = q1.w()*q2.w() - q1.x()*q2.x() - q1.y()*q2.y() - q1.z()*q2.z();
        q3.x() = q1.w()*q2.x() + q1.x()*q2.w() + q1.y()*q2.z() - q1.z()*q2.y();
        q3.y() = q1.w()*q2.y() + q1.y()*q2.w() + q1.z()*q2.x() - q1.x()*q2.z();
        q3.z() = q1.w()*q2.z() + q1.z()*q2.w() + q1.x()*q2.y() - q1.y()*q2.x();
        return q3;
    }

    Orientation inv(){
        return Orientation(w(), -x(), -y(), -z());
    }

    void rotateVector(Vec3D& vec){
        Orientation v_ori(0, vec.x(), vec.y(), vec.z());
        Orientation v_out = (*this) * v_ori * this->inv();
        vec.x() = v_out.x();
        vec.y() = v_out.y();
        vec.z() = v_out.z();
    }

    void setRPY(float roll, float pitch, float yaw){
        Orientation x_rot( cos(0.5*roll),  sin(0.5*roll),              0,            0);
        Orientation y_rot(cos(0.5*pitch),              0, sin(0.5*pitch),            0);
        Orientation z_rot(  cos(0.5*yaw),              0,              0, sin(0.5*yaw));

        Orientation q_out;
        q_out = q_out * x_rot;
        q_out = q_out * y_rot;
        q_out = q_out * z_rot;
        
        memcpy(data_, q_out.data_, sizeof(q_out.data_));
    }

    void print(){
        std::cout << "{" << w() << ", " << x() << ", " << y() << ", " << z() << "}" << std::endl;
    }

private:
    float data_[4] = {1.0f, 0.0f, 0.0f, 0.0f};
};

#endif
