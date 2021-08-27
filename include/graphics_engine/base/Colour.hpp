#ifndef COLOUR_HPP_
#define COLOUR_HPP_

struct Colour{
    Colour(){}

    Colour(float r, float g, float b, float a){
        data_[0] = r;
        data_[1] = g;
        data_[2] = b;
        data_[3] = a;
    }

    float& r() {return data_[0];}
    float& g() {return data_[1];}
    float& b() {return data_[2];}
    float& a() {return data_[3];}

    const float r() const {return data_[0];}
    const float g() const {return data_[1];}
    const float b() const {return data_[2];}
    const float a() const {return data_[3];}

    const float* data() const {return data_;}
    const uint dataSize() const {return sizeof(data_);}

private:
    float data_[4] = {0, 0, 0, 1};
};

#endif
