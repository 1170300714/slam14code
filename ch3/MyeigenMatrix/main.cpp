#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main(int argc, char **argv) {
//     //矩阵初始化及输出
//     Matrix<double,3,3> mat_33;
//     mat_33<<1,2,3,4,5,6,7,8,9;
//     // 1 2 3
//     // 4 5 6
//     // 7 8 9
//     cout<<mat_33<<endl;
    
    //初始化为0
    Matrix<double,5,5> mat_33 = MatrixXd::Zero();
    cout<<mat_33<<endl;
    return 0;
}
    