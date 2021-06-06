#pragma once

#include <iostream>
#include <cmath>
#include <fstream>

#include "Vector3D.hh"
//#include "Matrix3D.hh"


class Object {

    Vector3D LokCorners[CUBE];

    public:

        Object();

        Object(const Object &obj);

        Object(Vector3D ObjectCorners[CUBE]);

        Vector3D &operator [] (int index);

        const Vector3D &operator [] (int index) const;


        double &operator () (unsigned int row, unsigned int column);

        const double &operator () (unsigned int row, unsigned int column) const;

};

bool SaveToFile(const char *FileName,  Object &Obj);

std::ostream &operator << (std::ostream &out, const Object &Obj);