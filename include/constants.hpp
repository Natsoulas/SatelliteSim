#pragma once

// Physics constants:
namespace physics {
static constexpr double mu_Earth = 3.986004418E14; // gravitational parameter of earth m^3/s^2
static constexpr double radius_Earth = 6.371E6; // in meters
}

namespace sim {
static constexpr int state_size = 6; // x,y,z components of position and velocity;
}