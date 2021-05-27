#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <stdlib.h>

#include "exampleConfig.h"


int main() {

  char choise;

  double XL, YL, ZL;

  int center; //Central point of object(Vector3D)

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

          std::cout << "Enter central point of object" << std::endl;
          std::cin >> center;

          std::cout << "Enter object's value X Y Z" << std::endl;
          std::cin >> XL >> YL >> ZL;

          //CreateObj(center, XL, YL, ZL)

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
