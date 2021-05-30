#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif


#include <iostream>
#include <stdlib.h>

#include "exampleConfig.h"
#include "../include/lacze_do_gnuplota.hh"
#include "../include/Object.hh"
#include "../include/Scene.hh"


int main() {

  char choise;

  double XL, YL, ZL;

  int objectIndex = 0, ObjectIndex;

  std::string fileName = "../data/object";

  Vector3D startCorner, V; //Start point of object(Vector3D)

  Scene Sce;


  PzG::LaczeDoGNUPlota Lacze;

  //Lacze.DodajNazwePliku("../data/object1.dat", PzG::RR_Ciagly,2);

  Lacze.ZmienTrybRys(PzG::TR_3D);

  Lacze.UstawZakresY(0, 100);
  Lacze.UstawZakresX(0, 100);
  Lacze.UstawZakresZ(0, 100);

  std::cout << "C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR
            << "."
            << PROJECT_VERSION_MINOR
            << "."
            << PROJECT_VERSION_PATCH
            << "."
            << PROJECT_VERSION_TWEAK
            << std::endl;
  std::system("cat ../LICENSE");


  try {

    while (choise != 'f') {
      
      std::cout << "c - create new object" << std::endl;
      std::cout << "m - move object" << std::endl;
      std::cout << "f - finish program" << std:: endl;

      std::cout << "Your choise: " << std::endl;
      std::cin >> choise;

      switch(choise) {

        case 'f':

          choise = 'f';

        break;

        case 'c':

          int type;

          std::cout << "Enter start point of object" << std::endl;
          std::cin >> startCorner;

          std::cout << "Enter object's value X Y Z" << std::endl;
          std::cin >> XL >> YL >> ZL;

          std::cout << "Enter type of object" << std::endl;
          std::cout << "1 -> Cube" << std::endl;
          std::cout << "2 -> Pyramid" << std::endl;
          std::cout << "0 -> back" << std::endl;
          std::cin >> type;

          Sce.NewObject(startCorner, XL, YL, ZL, type, objectIndex);

          fileName = fileName + std::to_string(objectIndex) + ".dat";

          Lacze.DodajNazwePliku(fileName.c_str(),PzG::RR_Ciagly,2);

          Lacze.Rysuj();

          fileName = fileName = "../data/object";

          objectIndex += 1;
          
        break;

        case 'm':

          std::cout << "Give number for object" << std::endl;
          std::cin >> ObjectIndex;

          //if ObjInd < 0 or ObjInb > objInd -> runtimeError

          std::cout << "Give vector X Y Z" << std::endl;
          std::cin >> V;

          Sce.Translate(V, ObjectIndex - 1);

          fileName = fileName + std::to_string(ObjectIndex - 1) + ".dat";

          Lacze.DodajNazwePliku(fileName.c_str(),PzG::RR_Ciagly,2);

          Lacze.Rysuj();

          fileName = fileName = "../data/object";

        break;

      }

    }
     
  }

  catch(const std::runtime_error& e)  {

    std::cerr << "Something go wrong" << e.what() << '\n';

    exit(1);

  }

  return 0;
  

}
