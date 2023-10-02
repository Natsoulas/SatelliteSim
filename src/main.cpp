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

    int sim_duration = 300000*10; // seconds*10, as integration step size dt is 0.1 sec.

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
    double n = sqrt(physics::mu_Earth/pow(7167.0E3,3.0));

    //state << 12000,0,0,0,6.2355,0;
    state << 12000, 10000, 2000, 0, 5.30,10.0;

    cout << "Initial State Vector (rx, ry, rz, vx, vy, vz): " << state << endl;

    Matrix<double, 3, sim::state_size > K_LQR;
    //K_LQR << 0.0011, 0, 0, 0.0473, -0.000127, 0, 4.5452E-5, 9.9897E-04, 0, -1.0217E-4, 0.0447, 0, 0, 0, 0.0032, 0, 0, 0.0795;
    // This one was best: K_LQR << 3.8383E-6, -1.1014E-6, 0, 0.0020, 7.7590e-4, 0, 3.0269e-6, 1.7178e-7, 0, 6.2072e-4, 0.0016, 0, 0, 0, 2.2598e-6, 0, 0, 0.0021;
    K_LQR << 2.3609e-7, -1.3237e-8, 2.4147e-22, 6.7755e-05, 1.1001e-4, 1.9864e-19, 1.0878e-6, -2.9323e-8, -9.9355e-23, 8.8011e-5, 5.4589e-4, 1.1571e-20, 6.9589e-21, -8.6165e-23, 4.6081e-9, -2.5218e-19, 4.0818e-18, 9.6001e-5; 
    
    // Numerical Integration given initial state from above:
    for (int i = 0; i < sim_duration; i++)  {
        // Step the dynamics forward by a tenth of a second.
        Vector3d F(3);
        F = -K_LQR*state*spacecraft::m;
        double F_magnitude = F.norm();

        // Control Signal saturation cap.
        if (F_magnitude >0.450) {
             F = (F/F_magnitude)*0.450;
        }
        state = ralston4(&eom_cw, state, F, n);
       
        // Save off state and control data every second.
        if (i%10 == 0) {
        outputFile << i * 0.1 << ","
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