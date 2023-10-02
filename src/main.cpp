#include <iostream>
#include <fstream>
#include <string>
#include <Eigen/Dense>
#include <cmath>
#include "constants.hpp"
#include "simulation/eom.hpp"
#include "simulation/eom_cw.hpp"
#include "simulation/ralston4.hpp"

using namespace std;
using namespace Eigen;

int main() {

    int sim_duration = 60000*10; // seconds*10, as integration step size dt is 0.1 sec.

     // Create an ofstream object to write to a CSV file
    ofstream outputFile("simulated_state_history.csv");

    // Check if the file opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error opening the output file." << std::endl;
        return 1;
    }

    // Write header to the CSV file (optional)
    outputFile << "Time,Position_X,Position_Y,Position_Z,Velocity_X,Velocity_Y,Velocity_Z,U_X,U_Y,U_Z" << std::endl;


    // Initial State Vector (250km circular + equatorial earth orbit, and 10000km circuilar + equatorial orbit):
    Matrix<double, sim::state_size, 1> state;
    //Matrix<double, sim::state_size, 1> desired_state;
    double n = sqrt(physics::mu_Earth/pow(7167.0E3,3.0));

    state << 12000,0,0,0,6.2355,0;

    cout << "Initial State Vector (r, v): " << state << endl;
    // Null external force vector.
    Matrix<double, 3, sim::state_size > K_LQR;
    K_LQR << 0.0011, 0, 0, 0.0473, -0.000127, 0, 4.5452E-5, 9.9897E-04, 0, -1.0217E-4, 0.0447, 0, 0, 0, 0.0032, 0, 0, 0.0795;
 

    // Numerical Integration given initial state from above:
    for (int i = 0; i < sim_duration; i++)  {
        // Step the dynamics forward by a tenth of a second.
        Vector3d F(3);
        F = -K_LQR*state;
        double F_magnitude = F.norm();
        if (F_magnitude > 0.5) {
            F = (F/F_magnitude)*4.5;
        }
        state = ralston4(&eom_cw, state, F, n);
       
        //desired_state = ralston4(&eom, desired_state, F_des);
       
        if (i%10 == 0) {
        outputFile << i * 0.01 << ","
                   << state(0) << ","
                   << state(1) << ","
                   << state(2) << ","
                   << state(3) << ","
                   << state(4) << ","
                   << state(5) << ","
                   << F(0) << ","
                   << F(1) << ","
                   << F(2) << std::endl;
        }
    
    }
    outputFile.close();

    return 0;
}