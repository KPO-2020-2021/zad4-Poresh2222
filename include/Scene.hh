#pragma once

#include <cstdlib>
#include <cmath>
#include <vector>
#include <string.h>

#include "../include/Size.hh"
#include "../include/Object.hh"
#include "../include/Matrix3D.hh"

//

class Scene {

    std::vector <Object> Obj;

    std::vector <Vector3D> Vec;

    std::vector <Matrix3D> Mat;

    public:

        void NewObject(
            
            const Vector3D startCorner, 

            const double XL, 
            const double YL,
            const double ZL,

            const int type,

            int objectIndex
            
        );

        void Translate(const Vector3D, const int);

};