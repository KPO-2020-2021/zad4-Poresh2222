#pragma once

#include <cstdlib>
#include <cmath>
#include <vector>
#include <string.h>

#include "../include/Size.hh"
#include "../include/Object.hh"

//

class Scene {

    std::vector <Object> Obj;

    std::vector <Vector3D> Vec;

    public:

        void NewObject(
            
            const Vector3D startCorner, 

            const double XL, 
            const double YL,
            const double ZL,

            const int type
            
        );

};