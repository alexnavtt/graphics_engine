#ifndef POINT_HPP_
#define POINT_HPP_

#include <cstring>
#include "graphics_engine/base/Colour.hpp"

class Point{
public:
    /**
     * Access Point x element
     */
    float& x(){return data_[0];} const float& x() const {return data_[0];}

    /**
     * Access Point y element
     */
    float& y(){return data_[1];} const float& y() const {return data_[1];}

    /**
     * Access Point colour red component
     */
    float& r(){return data_[3];} const float& r() const {return data_[3];}

    /**
     * Access Point colour green component
     */
    float& g(){return data_[4];} const float& g() const {return data_[4];}

    /**
     * Access Point colour blue component
     */
    float& b(){return data_[5];} const float& b() const {return data_[5];}

    /**
     * Access Point colour alpha component
     */
    float& a(){return data_[6];} const float& a() const {return data_[6];}

    /**
     * Get the data of the point
     * @return      Data C-vector in the form (x, y, ?, r, g, b, a)
     *              The element ? depends on the type of point. It can
     *              be either z for a Point3D or depth for a Point2D
     */
    const float* data() const {return data_;}

    /**
     * Get the size of the data vector, which is 7*sizeof(float)
     */
    uint dataSize() const{return sizeof(data_);}

    /**
     * Set the colour of the point
     */
    void setColour(const Colour& c){
        memcpy(&data_[3], c.data(), sizeof(float)*4);
    }

    /**
     * Set the colour of the point
     */
    void setColour(float r, float g, float b, float a = 1){
        data_[3] = r;
        data_[4] = g;
        data_[5] = b;
        data_[6] = a;
    }
    
protected:
    /**
     * Data vector
     */
    float data_[7];
};

#endif
