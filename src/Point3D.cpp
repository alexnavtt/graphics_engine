#include "graphics_engine/ThreeDim/Point3D.hpp"

Point3D Point3D::operator +(const Vec3D& v) const {
    Point3D out;
    out.x() = v.x() + x();
    out.y() = v.y() + y();
    out.z() = v.z() + z();
    return out;
}

Vec3D Point3D::operator -(const Point3D& p) const {
    Vec3D out;
    out.x() = x() - p.x();
    out.y() = y() - p.y();
    out.z() = z() - p.z();
    return out;
}

Point3D Point3D::operator -(const Vec3D& v) const{
    return (-1.0f*v) + (*this);
}