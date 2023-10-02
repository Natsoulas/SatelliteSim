#include "constants.hpp"
#include <Eigen/Dense>
using namespace Eigen;

// Clohessy-Wiltshire Equations of Motion. (Necessary for LQR controlled Rendezvous.)
static Matrix<double, sim::state_size, 1>
eom_cw(const Matrix<double, sim::state_size, 1> &state, const Vector3d &F, const double &n) {
    double x = state(0);
    double y = state(1);
    double z = state(2);
    double xdot = state(3);
    double ydot = state(4);
    double zdot = state(5);
    const Vector3d a_thruster = F/spacecraft::m;
    double xddot = 3*n*n*x + 2*n*ydot + a_thruster(0);
    double yddot = -2*n*xdot + a_thruster(1);
    double zddot = -n*n*z + a_thruster(2);
    Matrix<double, sim::state_size, 1> state_derivative;
    state_derivative << xdot,ydot,zdot,xddot,yddot,zddot;
    return state_derivative;
}