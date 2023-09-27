#include <iostream>
#include <fstream>
#include <string>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main() {
    // Proof that I can use Eigen in C++ Dev :)
    Vector3d vec(3);
    vec << 6.9, 4.2, 0.2;
    cout << "Hello Eigen: " << vec << endl;
    return 0;
}