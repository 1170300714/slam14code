#include <iostream>
#include <ctime>
using namespace std;
#include <Eigen/Core>
#include <Eigen/Dense>
#define Max_Size 100
using namespace Eigen;

int main(int argc, char **argv) {
    Matrix<double, Dynamic, Dynamic> mat_nn;
    Matrix<double, Dynamic, Dynamic> v;
    mat_nn = MatrixXd::Random(Max_Size,Max_Size);
    v = MatrixXd::Random(Max_Size,1);
    Matrix<double,Dynamic,Dynamic> mat_nn_sym = mat_nn.array().abs();
    for(int i=0;i<Max_Size;i++){
	for(int j=0;j<Max_Size;j++){
	    mat_nn_sym(i,j) = mat_nn_sym(j,i);
	}
    }
    //乘逆
    Matrix<double, Dynamic, Dynamic>x1 = mat_nn_sym.inverse()*v;
    cout<<"乘逆：\n"<<x1<<endl<<endl;
    
    //QR
    Matrix<double, Dynamic, Dynamic>x2 = mat_nn_sym.colPivHouseholderQr().solve(v);
    cout<<"QR：\n"<<x2<<endl<<endl;
    
    //Cholesky
    Matrix<double, Dynamic, Dynamic> x3 = mat_nn_sym.ldlt().solve(v);
    cout<<"Cholesky：\n"<<x3<<endl;
    return 0;
}
