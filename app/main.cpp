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

  std::string fileName = "../data/object";

  Vector3D startCorner; //Central point of object(Vector3D)

  Scene Sce;


  PzG::LaczeDoGNUPlota Lacze;

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

          Sce.NewObject(startCorner, XL, YL, ZL, type);

          Lacze.DodajNazwePliku("../data/object.dat",PzG::RR_Ciagly,2);
          Lacze.Rysuj();
          
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
