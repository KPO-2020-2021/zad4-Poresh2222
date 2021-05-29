#include "../include/Scene.hh"


void Scene::NewObject(

        const Vector3D startCorner,

        const double XL,
        const double YL,
        const double ZL,

        const int type

    ) {

    Vector3D sizeTab;

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
                (i == 7 && j != 0) ) {

                cornersTab[i][j] = cornersTab[i][j] + sizeTab[j];

            }

        }

    }

    Object Obj(cornersTab);

    std::cout << Obj << std::endl;

    SaveToFile("../data/object.dat", Obj);

    std::cout << type << std::endl;

}