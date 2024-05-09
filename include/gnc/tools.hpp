#pragma once
#include <Eigen/Dense>
using Eigen::Vector3d;
using Eigen::Vector4d;


inline Vector4d quaternion_derivative(const Vector4d &q, const Vector3d &w) {
    Vector4d w_q_space(0.0, w(0), w(1), w(2));
    Eigen::Matrix4d Q;
    Q << q(0), -q(1), -q(2), -q(3),
         q(1), q(0), -q(3), q(2),
         q(2), q(3), q(0), -q(1),
         q(3), -q(2), q(1), q(0);
    static constexpr double half = 1.0/2.0;
    Eigen::Vector4d qdot;
    qdot << half*Q*w_q_space;
    return qdot;
}