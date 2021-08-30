#include "graphics_engine/ThreeDim/Observer.hpp"
#include "graphics_engine/TwoDim/Triangle2D.hpp"
#include "graphics_engine/base/Display.hpp"

Point2D Observer::project(const Point3D& p3D){
    Point2D p2D;
    p2D.setColour({p3D.r(), p3D.g(), p3D.b(), p3D.a()});
    Vec3D offset = p3D - Point3D(0, 0, 0);

    // Transform the point such that the observer
    // is at the point (0,0,0) with identity rotation
    offset.x() -= loc.x();
    offset.y() -= loc.y();
    offset.z() -= loc.z();

    ori.inv().rotateVector(offset);

    // Determine the point of intersection of the ray between the observer
    // and the Point3D with the Display
    float ratio = screen_dist/offset.x();
    p2D.x() = -offset.y() * ratio;
    p2D.y() = offset.z() * ratio;
    p2D.depth() = 1 - ratio;
    return p2D;
}

void Observer::drawMesh(const Mesh& mesh, const Display& disp){
    if (!mesh.use_element_array){
        for (Triangle3D T : mesh.triangles){
            Triangle2D tri = project(T);
            disp.drawTriangle(tri);
        }
    }
    else{
        // Project all of the 3D points onto the 2D plane
        std::vector<Point2D> points_2d;
        points_2d.reserve(mesh.points.size());
        for (const Point3D& point_3d : mesh.points){
            points_2d.push_back(project(point_3d));
        }

        // Draw the elements
        disp.drawTriangleArray(points_2d, mesh.indices);
    }
}

Triangle2D Observer::project(const Triangle3D& tri3D){
    Triangle2D tri2D;
    tri2D.colour = tri3D.colour;

    tri2D.p1 = project(tri3D.p1);
    tri2D.p2 = project(tri3D.p2);
    tri2D.p3 = project(tri3D.p3);

    return tri2D;
}
