#include <iostream>
#include <fstream>
#include <string>
#include <Eigen/Dense>
#include "constants.hpp"
#include "simulation/eom.hpp"
#include "simulation/ralston4.hpp"

using namespace std;
using namespace Eigen;

int main() {

    int sim_duration = 5544*100; // seconds*10, as integration step size dt is 0.1 sec.

    // Initial State Vector (400km circular + equatorial earth orbit):
    Matrix<double, sim::state_size, 1> state;

    state << physics::radius_Earth + 400e3, 0, 0, 0, 7672.598648385013, 0;
    cout << "Initial State Vector (r, v): " << state << endl;

    // Null external force vector.
    Vector3d F(3);
    F << 0.0,0.0,0.0;
    
    // VectorXd state_derivative(6);
    // state_derivative = eom(state, F);
    // cout << "Initial State Derivative Vector (v, a): " << state_derivative << endl;

    // Numerical Integration given initial state from above:
    for (int i = 0; i < sim_duration; i++)  {
        // Step the dynamics forward by a tenth of a second.
        state = ralston4(&eom, state, F);
        if (i%100 == 0) {
        cout << "State Vector: " << state << endl;
        }
    }
    return 0;
}