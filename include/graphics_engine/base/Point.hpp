#ifndef POINT_HPP_
#define POINT_HPP_

#include "graphics_engine/base/Colour.hpp"

class Point{
public:
    float& x(){return data_[0];}
    float& y(){return data_[1];}
    float& r(){return data_[3];}
    float& g(){return data_[4];}
    float& b(){return data_[5];}
    float& a(){return data_[6];}

    const float& x() const {return data_[0];}
    const float& y() const {return data_[1];}
    const float& r() const {return data_[3];}
    const float& g() const {return data_[4];}
    const float& b() const {return data_[5];}
    const float& a() const {return data_[6];}

    const float* data() const {return data_;}
    uint dataSize() const{return sizeof(data_);}

    void setColour(const Colour& c){
        memcpy(&data_[3], c.data(), sizeof(float)*4);
    }
protected:
    float data_[7];
};

#endif
