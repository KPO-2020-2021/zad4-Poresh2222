#include "Object.hh"


Object::Object() {

    for (int i = 0; i < CUBE; ++i) {

        for (int j = 0; j < 3; ++j) {

            LokCorners[i][j] = 0;

        }

    }

}

Object::Object(const Object &obj) {

    for (int i = 0; i < CUBE; ++i) {
        
        for (int j = 0; j < 3; ++j) {

            LokCorners[i][j] = obj(i, j);

        }
        
    }

}

double &Object::operator () (unsigned int row, unsigned int column) {

    if (row >= CUBE || column >= 3) {

        throw std::runtime_error("Error: The Matrix is out of range \n");

    }

    return LokCorners[row][column];

}

const double &Object::operator () (unsigned int row, unsigned int column) const {

    if (row >= CUBE || column >= 3) {

        throw std::runtime_error("Error: The Matrix is out of range \n");
    
    }

    return LokCorners[row][column];

}

std::ostream &operator<<(std::ostream &out, Object const &Obj) {
    
    for(int i = 0; i < CUBE; ++i) {

        for(int j = 0; j < 3; ++j) {

            out << std::fixed << std::setprecision(10) << Obj(i , j ) << "\t";
        
        }

        out << std::endl;
    
    }

  return out;

}

bool SaveToFile(const char *FileName, Object &Obj) {
    std::ofstream file;

    file.open(FileName);

    if (!file.is_open()) {

        std::cerr << "Operacja otwarcia do zapisu \"" << FileName << "\"" << std::endl
	    << "nie powiodla sie." << std::endl;

       return false;

    }

    file << Obj;
    file << Obj(0, 0)<< "    " << Obj(0, 0);

    file.close();

    return !file.fail();
}