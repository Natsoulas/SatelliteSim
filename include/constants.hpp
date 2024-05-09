#pragma once
#include <Eigen/Dense>


// Physics constants:
namespace physics {
static constexpr double mu_Earth = 3.986004418E14; // gravitational parameter of earth m^3/s^2
static constexpr double radius_Earth = 6.371E6; // in meters
}

// Simulation Constants.
namespace sim {
static constexpr int state_size = 13; // x,y,z components of position and velocity
static constexpr double dt = 0.01; // h is the fixed step size for the numerical integration (s).
}

// Spacecraft Constants.
namespace spacecraft {
    static constexpr int m = 500; // mass of spacecraft in kg
    static constexpr double Ixx = 1.0; // xx component of inertia matrix;
    static constexpr double Iyy = 1.0; // yy component of inertia matrix;
    static constexpr double Izz = 1.0; // zz component of inertia matrix;
}
