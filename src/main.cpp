#include <iostream>
#include <fstream>
#include <string>
#include <Eigen/Dense>
#include <cmath>
#include "constants.hpp"
#include "simulation/eom.hpp"
#include "simulation/ralston4.hpp"

using namespace std;
using namespace Eigen;

int main() {

    int sim_duration = 10000*10; // seconds*10, as integration step size dt is 0.1 sec.

     // Create an ofstream object to write to a CSV file
    ofstream outputFile("simulated_state_history.csv");

    // Check if the file opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error opening the output file." << std::endl;
        return 1;
    }

    // Write header to the CSV file (optional)
    outputFile << "Time,Position_X,Position_Y,Position_Z,Velocity_X,Velocity_Y,Velocity_Z,Position_X_des,Position_Y_des,Position_Z_des,Velocity_X_des,Velocity_Y_des,Velocity_Z_des" << std::endl;


    // Initial State Vector (250km circular + equatorial earth orbit, and 10000km circuilar + equatorial orbit):
    Matrix<double, sim::state_size, 1> state;
    Matrix<double, sim::state_size, 1> desired_state;

    state << physics::radius_Earth + 250e3, 0, 0, 0, sqrt(physics::mu_Earth/(physics::radius_Earth + 250e3)), 0;
    desired_state << physics::radius_Earth + 10000e3, 0, 0, 0, sqrt(physics::mu_Earth/(physics::radius_Earth + 10000e3)), 0;

    cout << "Initial State Vector (r, v): " << state << endl;
    cout << "Initial Target State vector (r, v): " << desired_state << endl;
    // Null external force vector.
    Vector3d F(3);
    F << 0.0,0.0,0.0;
    Vector3d F_des(3);
    F_des << 0.0,0.0,0.0;
    // VectorXd state_derivative(6);
    // state_derivative = eom(state, F);
    // cout << "Initial State Derivative Vector (v, a): " << state_derivative << endl;

    // Numerical Integration given initial state from above:
    for (int i = 0; i < sim_duration; i++)  {
        // Step the dynamics forward by a tenth of a second.
        state = ralston4(&eom, state, F);
        desired_state = ralston4(&eom, desired_state, F_des);
        if (i%10 == 0) {
        outputFile << i * 0.01 << ","
                   << state(0) << ","
                   << state(1) << ","
                   << state(2) << ","
                   << state(3) << ","
                   << state(4) << ","
                   << state(5) << ","
                   << desired_state(0) << ","
                   << desired_state(1) << ","
                   << desired_state(2) << ","
                   << desired_state(3) << ","
                   << desired_state(4) << ","
                   << desired_state(5) << std::endl;
        }
    
    }
    outputFile.close();

    return 0;
}