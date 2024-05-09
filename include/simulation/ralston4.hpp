#pragma once
#include <Eigen/Dense>
#include "constants.hpp"
using namespace Eigen;

// Ralston's 4th order method for a numerical integration step.

template <typename T>
T ralston4(T (*f)(T const &state, const Vector3d &F, const Vector3d &Tau), T const &x, const Vector3d &F, const Vector3d &Tau) {
    static constexpr double one_sixth = 1.0 / 6.0;
    static constexpr double two_thirds = 2.0 / 3.0;
    static constexpr double one_third = 1.0 / 3.0;
    
    // Calculate intermediate values.
    auto k1 = f(x, F, Tau);
    auto k2 = f(x + sim::dt * (two_thirds * k1), F, Tau);
    auto k3 = f(x + sim::dt * (one_third * k1 + two_thirds * k2), F, Tau);
    auto k4 = f(x + sim::dt * (one_sixth * k1 + one_sixth * k3 + two_thirds * k2), F,Tau);

    // Update the state using Ralston's method.
    auto new_x = x + sim::dt * (one_sixth * k1 + one_sixth * k3 + two_thirds * k2);
    return new_x;
}
