#pragma once

#include "Size.hh"
#include <iostream>
#include <iomanip>


template <unsigned int Size>

class Vector {

    double size[Size];

    public:

        Vector<Size>();

        Vector<Size>(double [Size]);


        Vector<Size> operator + (const Vector<Size> &V);

        Vector<Size> operator - (const Vector<Size> &V);

        Vector<Size> operator * (const double &tmp);

        Vector<Size> operator / (const double &tmp);


        const double &operator [] (unsigned int index) const;

        double &operator [] (unsigned int index);


        bool operator == (const Vector& tmp);

};

template <unsigned int Size>

std::ostream &operator << (std::ostream &out, Vector<Size> const &tmp);


template <unsigned int Size>

std::istream &operator >> (std::istream &in, Vector<Size> &tmp);