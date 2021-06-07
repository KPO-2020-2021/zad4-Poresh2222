#pragma once

#include <cstdlib>
#include <cmath>
#include <vector>
#include <string.h>

#include "../include/Size.hh"
#include "../include/Object.hh"
#include "../include/Matrix3D.hh"

class Scene {

    std::vector <Object> Obj;

    std::vector <Vector3D> Vec;

    std::vector <Matrix3D> MatrixDef;

    std::vector <Matrix3D> MatrixShadow;

    public:

        void NewObject(
            
            const Vector3D, 

            const Vector3D,

            const int 
            
        );

        void Translate(
            
            const Vector3D, 
            
            const int
            
        );

        void PreRotateObject(

            char,

            double,

            const int,

            const int

        );

        void RotateObject(

            const int,

            const int

        );

        void ShowInfo(

            const int
        
        );

        void ChekSize(

            const int

        );

};