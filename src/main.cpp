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

    int sim_duration = 5544*(1/sim::dt); // Convert total seconds to number of timesteps.

     // Create an ofstream object to write to a CSV file
    ofstream outputFile("simulated_state_history.csv");

    // Check if the file opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error opening the output file." << std::endl;
        return 1;
    }

    // Write header to the CSV file (optional)
    outputFile << "Time,Position_X,Position_Y,Position_Z,Velocity_X,Velocity_Y,Velocity_Z,Quaternion_S,Quaternion_X,Quaternion_Y,Quaternion_Z,AngV_X,AngV_Y,AngV_Z" << std::endl;


    // Initial State Vector (400km circular + equatorial earth orbit):
    Matrix<double, sim::state_size, 1> state;

    state << physics::radius_Earth + 400e3, 0, 0, 0, 7672.598648385013, 0, 0, 0, 0, 0, 0, 0, 0;
    cout << "Initial State Vector (r, v, q, w): " << state << endl;

    // Null external force vector.
    Vector3d F(3);
    F << 0.0,0.0,0.0;

    // Null external torque vector.
    Vector3d Tau(3);
    Tau << 0.0,0.0,0.0;

    // Numerical Integration given initial state from above:
    for (int i = 0; i < sim_duration; i++)  {
        // Step the dynamics forward by a single step.
        state = ralston4(&eom, state, F, Tau);
        // Save state at each step to output CSV file.
        outputFile << i * sim::dt << ","
                   << state(0) << ","
                   << state(1) << ","
                   << state(2) << ","
                   << state(3) << ","
                   << state(4) << ","
                   << state(5) << ","
                   << state(6) << ","
                   << state(7) << ","
                   << state(8) << ","
                   << state(9) << ","
                   << state(10) << ","
                   << state(11) << ","
                   << state(12) << std::endl;
    }
    outputFile.close();

    return 0;
}