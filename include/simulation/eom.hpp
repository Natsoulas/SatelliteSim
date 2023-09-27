#pragma once
#include "constants.hpp"
#include <Eigen/Dense>
using namespace Eigen;

static Matrix<double, sim::state_size, 1>
eom(const Matrix<double, sim::state_size, 1> &state, const Vector3d &F) {
    Vector3d r = state.block<3,1>(0,0);
    Vector3d v = state.block<3,1>(3,0);
    Vector3d a = -physics::mu_Earth*r/(pow(r.norm(), 3.0));
    Matrix<double, sim::state_size, 1> state_derivative;
    state_derivative << v, a;
    return state_derivative;
}