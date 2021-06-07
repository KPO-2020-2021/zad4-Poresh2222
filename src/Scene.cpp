#include "../include/Scene.hh"
#include "../include/Size.hh"
#include "../include/Matrix3D.hh"


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


    std::string fileName = "../data/object";
    fileName = fileName + std::to_string(objectIndex) + ".dat";
    SaveToFile(fileName.c_str(), obj);

    Obj.push_back(obj);

}

void Scene::Translate(
    
        const Vector3D V, 
    
        const int ObjectIndex
    
    ) {

    Vector3D tmp = V;

    Vec.at(ObjectIndex) = Vec.at(ObjectIndex) + tmp;

    for (int i = 0; i < CUBE; ++i) {

        for (int j = 0; j < SIZE; ++j) {

            Obj.at(ObjectIndex)(i, j) = Obj.at(ObjectIndex)(i, j) + tmp[j];

        }

    }

    std::string fileName = "../data/object";
    fileName = fileName + std::to_string(ObjectIndex) + ".dat";
    SaveToFile(fileName.c_str(), Obj.at(ObjectIndex));

}

void Scene::PreRotateObject(
    
        char axis, 
        
        double angle, 
        
        const int iterations, 
        
        const int ObjectIndex
        
    ) {

    MatrixDef.at(ObjectIndex) = MatrixShadow.at(ObjectIndex);

    if (axis == 'x' || 'X') {

        MatrixDef.at(ObjectIndex) = Rotate_X(angle);

    } else if (axis == 'y' || 'Y') {

        MatrixDef.at(ObjectIndex) = Rotate_Y(angle);

    } else if (axis == 'z' || 'Z') {

        MatrixDef.at(ObjectIndex) = Rotate_Z(angle);

    }

    RotateObject(iterations, ObjectIndex);

}

void Scene::RotateObject(

        const int iterations,

        const int ObjectIndex

    ) {

    Matrix3D matrix = MatrixDef.at(ObjectIndex);

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

void Scene::ShowInfo(
    
        const int ObjectIndex
        
    ) {

    std::cout << Obj.at(ObjectIndex) << std::endl;

    std::cout << Vec.at(ObjectIndex) << std::endl;

    std::cout << MatrixDef.at(ObjectIndex) << std::endl;

    std::cout << MatrixShadow.at(ObjectIndex) << std::endl;

}

void Scene::ChekSize(

        const int ObjectIndex

    ) {

    int x = 0, y = 0, z = 0;

    Vector4D X, Y, Z;

    Object obj = Obj.at(ObjectIndex);

    for (int i = 0; i < CUBE; ++i) {

        for (int j = 0; j < SIZE; ++j) {

            if ((i == 1 && j == 0) || (i == 5 && j == 0)) {

                X[x] = obj(i ,j) - obj(i - 1, j);

                x++;

            } else if ((i == 3 && j == 0) || (i == 7 && j == 0)) {

                X[x] = obj(i - 1, j) - obj(i, j);

                x++;

            } else if ((i == 0 && j == 1) || (i == 4 && j == 1)) {

                Y[y] = obj(i + 3, j) - obj(i, j);

                y++;

            } else if ((i == 1 && j == 1) || (i == 5 && j == 1)) {

                Y[y] = obj(i + 1, j) - obj(i, j);

                y++;

            } else if ((i == 0 && j == 2) || ((i == 1 && j == 2))) {

                Z[z] = obj(i + 4, j) - obj(i, j);

                z++;

            } else if ((i == 3 && j == 2) || (i == 2 && j == 2)) {

                Z[z] = obj(i + 4, j) - obj(i, j);

                z++;

            }

            std::cout << x << std::endl;
            std::cout << "///" << std::endl;
            std::cout << y << std::endl;
            std::cout << "///" << std::endl;
            std::cout << z << std::endl;

        }

    }

    if (X[0] == X[1] && X[2] == X[3]) {

        std::cout << "X is eqal ->\n" << X[0] << " = " << X[1] << "\n" <<
                                         X[2] << " = " << X[3] << "\n" << std::endl;

    } else {

        std::cout << "X is not eqal ->\n" << X[0] << " = " << X[1] << "\n" <<
                                             X[2] << " = " << X[3] << "\n" << std::endl;

    }

    if (Y[0] == Y[1] && Y[2] == Y[3]) {

        std::cout << "Y is eqal ->\n" << Y[0] << " = " << Y[1] << "\n" <<
                                         Y[2] << " = " << Y[3] << "\n" << std::endl;

    } else {

        std::cout << "Y is not eqal ->\n" << Y[0] << " = " << Y[1] << "\n" <<
                                             Y[2] << " = " << Y[3] << "\n" << std::endl;

    }

    if (Z[0] == Z[1] && Z[2] == Z[3]) {

        std::cout << "Z is eqal ->\n" << Z[0] << " = " << Z[1] << "\n" <<
                                         Z[2] << " = " << Z[3] << "\n" << std::endl;

    } else {

        std::cout << "Z is not eqal ->\n" << Z[0] << " = " << Z[3] << "\n" <<
                                             Z[1] << " = " << Z[2] << "\n" << std::endl;

    }

}