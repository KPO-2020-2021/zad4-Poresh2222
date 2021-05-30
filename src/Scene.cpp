#include "../include/Scene.hh"
#include "../include/Size.hh"


void Scene::NewObject(

        const Vector3D startCorner,

        const double XL,
        const double YL,
        const double ZL,

        const int type,

        int objectIndex

    ) {

    Vec.push_back(startCorner);

    std::string fileName = "../data/object";
    fileName = fileName + std::to_string(objectIndex) + ".dat";

    Vector3D sizeTab, tmp;

    for (int i = 0; i < SIZE; ++i) {

        if (i == 0) {

            sizeTab[i] = XL;

        } else if (i == 1) {

            sizeTab[i] = YL;

        } else {

            sizeTab[i] = ZL;

        }

    }

    double cornersTab[8][3];

    for (int i = 0; i < CUBE; ++i) {

        for (int j = 0; j < SIZE; ++j) {

            cornersTab[i][j] = startCorner[j];

            if ((i == 1 && j == 0) || 
                (i == 2 && j != 2) || 
                (i == 3 && j == 1) ||
                (i == 4 && j == 2) ||
                (i == 5 && j != 1) ||
                (i == 6 && j != 3) ||
                (i == 7 && j != 0) ){

                cornersTab[i][j] = cornersTab[i][j] + sizeTab[j];

            }

        }

    }

    Object obj(cornersTab);

    std::cout << obj << std::endl;

    SaveToFile(fileName.c_str(), obj);

    std::cout << type << std::endl;

    Obj.push_back(obj);

}

void Scene::Translate(const Vector3D V, const int ObjectIndex) {
    Vector3D tmp = V;

    std::string fileName = "../data/object";
    fileName = fileName + std::to_string(ObjectIndex) + ".dat";

    Vec.at(ObjectIndex) = Vec.at(ObjectIndex) + tmp;

    for (int i = 0; i < CUBE; ++i) {

        for (int j = 0; j < SIZE; ++j) {

            Obj.at(ObjectIndex)(i, j) = Obj.at(ObjectIndex)(i, j) + tmp[j];

        }

    }

    SaveToFile(fileName.c_str(), Obj.at(ObjectIndex));

}