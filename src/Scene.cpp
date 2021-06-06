#include "../include/Scene.hh"
#include "../include/Size.hh"
#include "../include/Matrix3D.hh"


std::string fileName = "../data/object";

void Scene::NewObject(

        const Vector3D startCorner,

        const Vector3D sizeTab,

        const int objectIndex

    ) {

    Vector3D objectTab[CUBE];

    Matrix3D matrixDef, matrixShadow;


    Vec.push_back(startCorner);

    MatrixDef.push_back(matrixDef);

    MatrixShadow.push_back(matrixShadow);


    for (int i = 0; i < CUBE; ++i) {

        for (int j = 0; j < SIZE; ++j) {

            if ((i == 1 && j == 0) || 
                (i == 2 && j != 2) || 
                (i == 3 && j == 1) ||
                (i == 4 && j == 2) ||
                (i == 5 && j != 1) ||
                (i == 6 && j != 3) ||
                (i == 7 && j != 0) ){

                objectTab[i][j] = startCorner[j] + sizeTab[j];

                //std::cout << "**---------------------------------------------**\n" << std::endl;
                //std::cout << ObjectTab[i][j] << std::endl;
                //std::cout << "**---------------------------------------------**\n" << std::endl;

            } else {

                objectTab[i][j] = startCorner[j];

            }

        }      

    }

    Object obj(objectTab);

    std::cout << obj << std::endl;


    fileName = fileName + std::to_string(objectIndex) + ".dat";
    SaveToFile(fileName.c_str(), obj);

    Obj.push_back(obj);

}

void Scene::Translate(const Vector3D V, const int ObjectIndex) {
    Vector3D tmp = V;

    Vec.at(ObjectIndex) = Vec.at(ObjectIndex) + tmp;

    for (int i = 0; i < CUBE; ++i) {

        for (int j = 0; j < SIZE; ++j) {

            Obj.at(ObjectIndex)(i, j) = Obj.at(ObjectIndex)(i, j) + tmp[j];

        }

    }

    fileName = fileName + std::to_string(ObjectIndex) + ".dat";
    SaveToFile(fileName.c_str(), Obj.at(ObjectIndex));

    std::string fileName = "../data/object";

}

void Scene::PreRotateObject(
    
        char axis, 
        
        double angle, 
        
        const int iterations, 
        
        const int ObjectIndex
        
    ) {

    MatrixDef.at(ObjectIndex) = MatrixShadow.at(ObjectIndex);

    if (axis == 'x' || 'X') {

        MatrixDef.at(ObjectIndex) = MatrixDef.at(ObjectIndex) * Rotate_X(angle);

    } else if (axis == 'y' || 'Y') {

        MatrixDef.at(ObjectIndex) = MatrixDef.at(ObjectIndex) * Rotate_Y(angle);

    } else if (axis == 'z' || 'Z') {

        MatrixDef.at(ObjectIndex) = MatrixDef.at(ObjectIndex) * Rotate_Z(angle);

    }

    RotateObject(iterations, ObjectIndex);

}

void Scene::RotateObject(

        const int iterations,

        const int ObjectIndex

    ) {

        Matrix3D matrix = MatrixDef.at(ObjectIndex);


        std::cout << Obj.at(ObjectIndex) << std::endl;


        for (int i = 0; i < iterations; ++i) {

            for (int j = 0; j < CUBE; ++j) {

                Obj.at(ObjectIndex)[j] = matrix * Obj.at(ObjectIndex)[j];

            }

        }

        std::cout << Obj.at(ObjectIndex) << std::endl;

        std::string fileName = "../data/object";

        fileName = fileName + std::to_string(ObjectIndex) + ".dat";
        SaveToFile(fileName.c_str(), Obj.at(ObjectIndex));

    }