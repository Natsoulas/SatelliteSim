#include "constants.hpp"
#include "gnc/tools.hpp"
#include <Eigen/Dense>
using namespace Eigen;

static Matrix<double, sim::state_size, 1>
eom(const Matrix<double, sim::state_size, 1> &state, const Vector3d &F, const Vector3d &Tau) {
    Vector3d r = state.block<3,1>(0,0);
    Vector3d v = state.block<3,1>(3,0);
    Vector4d q = state.block<4,1>(6,0);
    Vector3d w = state.block<3,1>(10,0);
    Matrix3d I;
    I << spacecraft::Ixx, 0.0, 0.0, 0.0, spacecraft::Iyy, 0.0, 0.0, 0.0, spacecraft::Izz;
    Vector3d a = -physics::mu_Earth*r/(pow(r.norm(), 3.0)) + F/spacecraft::m;
    Vector4d qdot = quaternion_derivative(q, w);
    Vector3d wdot = I.inverse()*Tau;
    Matrix<double, sim::state_size, 1> state_derivative;
    state_derivative << v, a, qdot, wdot;
    return state_derivative;
}