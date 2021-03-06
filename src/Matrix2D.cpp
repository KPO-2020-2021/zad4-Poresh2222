#include "../include/Matrix2D.hh"


Matrix2D Rotate(const double angle) {
    Matrix2D M2;

    M2(0, 0) = cos(angle * M_PI  / 180.0);
    M2(0,1) = -sin(angle * M_PI / 180.0);
    M2(1,0) = sin(angle * M_PI / 180.0);
    M2(1,1) = cos(angle * M_PI/ 180.0);

    return M2;
}