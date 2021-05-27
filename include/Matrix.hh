#pragma once

#include "Vector.hh"
#include "Size.hh"

#include <iostream>
#include <cstdlib>
#include <cmath>


template <unsigned int Size>
class Matrix {

    double value[Size][Size];

    public:

        Matrix();

        Matrix(double [Size][Size]);


        Vector<Size> operator * (const Vector<Size> tmp);


        Matrix operator + (const Matrix tmp);

        Matrix operator * (const Matrix tmp);


        double &operator () (unsigned int row, unsigned int column);

        const double &operator () (unsigned int row, unsigned int column) const;

        bool operator == (const Matrix tmp);

};

template <unsigned int Size>

std::istream &operator>>(std::istream &in, Matrix<Size> &mat);


template <unsigned int Size>

std::ostream &operator<<(std::ostream &out, Matrix<Size> const &mat);