#include <iostream>
#include <fstream>
#include <string>
#include <Eigen/Dense>
#include "constants.hpp"
#include "simulation/eom.hpp"

using namespace std;
using namespace Eigen;

int main() {
    // Initial State Vector (400km circular + equatorial earth orbit):
    VectorXd state(6);
    state << physics::radius_Earth + 400e3, 0, 0, 0, 7672.598648385013, 0;
    cout << "Initial State Vector (r, v): " << state << endl;
    Vector3d F(3);
    F << 0.0,0.0,0.0;
    VectorXd state_derivative(6);
    state_derivative = eom(state, F);
    cout << "Initial State Derivative Vector (v, a): " << state_derivative << endl; 
    return 0;
}