#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
using namespace std;
using namespace Eigen;
int main(int argc, char **argv) {
    //define the object's coordinate in 3 different Coordinate system
    Vector3d p0;
    Vector3d p1(0.5, -0.1, 0.2);
    Vector3d p2;
    
    //define the first robot
    Quaterniond q1(0.55, 0.3, 0.2, 0.2);
    Vector3d t1(0.7, 1.1, 0.2);
    
    //define the second robot
    Quaterniond q2(-0.1, 0.3, -0.7, 0.2);
    Vector3d t2(-0.1, 0.4, 0.8);
    
    //define the transformation matrix
    Isometry3d Tc1w = Isometry3d::Identity();
    Isometry3d Tc2w = Isometry3d::Identity();
    
    //Position normalization
    Quaterniond q1n = q1.normalized();
    Quaterniond q2n = q2.normalized();
    
    //Quaternion1 to the Rotation matrix
    Matrix3d q1_m = q1n.toRotationMatrix();
    Tc1w.rotate(q1_m);
    Tc1w.pretranslate(t1);
    
    //Quaternion2 to the Rotation matrix
    Matrix3d q2_m = q2n.toRotationMatrix();
    Tc2w.rotate(q2_m);
    Tc2w.pretranslate(t2);
    
    //calculate the coordinate in the world coordinate system
    p0 = Tc1w.inverse()*p1;
    
    //calculate the coordinate in the second robot coordinate system
    p2 = Tc2w*p0;
    
    //cout<<p2.transpose()<<endl;
    cout<<q1.coeffs()<<endl;
    return 0;
}
