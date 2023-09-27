#include <iostream>
#include <fstream>
#include <string>
#include <Eigen/Dense>
#include "constants.hpp"
using namespace std;
using namespace Eigen;

int main() {
    // Initial State Vector (400km circular + equatorial earth orbit):
    VectorXd state(6);
    state << physics::radius_Earth + 400e3, 0, 0, 0, 7672.598648385013, 0;
    cout << "Initial State Vector (r, v): " << state << endl;
    return 0;
}