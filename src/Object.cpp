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

Object::Object(Vector3D tmp[CUBE]) {

    for (unsigned int i = 0; i < CUBE; ++i) {
            
        LokCorners[i] = tmp[i];

    }

}


Vector3D &Object::operator[](int index) {

    return const_cast<Vector3D &>(const_cast<const Object *>(this)->operator[](index));

}

const Vector3D &Object::operator [] (int index) const {

    if (index < 0 || index >= CUBE) {

        throw std::runtime_error("Error: Vec out of range!");

    }

    return LokCorners[index];
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

    //file << Obj(0, 0) << "   " << Obj(0, 1) << "   " << Obj(0, 2);
    //file << Obj(1, 0) << "   " << Obj(1, 1) << "   " << Obj(1, 2);
    //file << Obj(2, 0) << "   " << Obj(2, 1) << "   " << Obj(2, 2);
    //file << Obj(3, 0) << "   " << Obj(3, 1) << "   " << Obj(3, 2);
    //file << Obj(4, 0) << "   " << Obj(4, 1) << "   " << Obj(4, 2);
    //file << Obj(5, 0) << "   " << Obj(5, 1) << "   " << Obj(5, 2);
    //file << Obj(6, 0) << "   " << Obj(6, 1) << "   " << Obj(6, 2);
    //file << Obj(7, 0) << "   " << Obj(7, 1) << "   " << Obj(7, 2);

    file << Obj(0, 0) << "   " << Obj(0, 1) << "   " << Obj(0, 2) << "\n";
    file << Obj(1, 0) << "   " << Obj(1, 1) << "   " << Obj(1, 2) << "\n";
    file << Obj(2, 0) << "   " << Obj(2, 1) << "   " << Obj(2, 2) << "\n";
    file << Obj(3, 0) << "   " << Obj(3, 1) << "   " << Obj(3, 2) << "\n";

    file << Obj(0, 0) << "   " << Obj(0, 1) << "   " << Obj(0, 2) << "\n";

    file << Obj(4, 0) << "   " << Obj(4, 1) << "   " << Obj(4, 2) << "\n";
    file << Obj(5, 0) << "   " << Obj(5, 1) << "   " << Obj(5, 2) << "\n";
    file << Obj(6, 0) << "   " << Obj(6, 1) << "   " << Obj(6, 2) << "\n";
    file << Obj(7, 0) << "   " << Obj(7, 1) << "   " << Obj(7, 2) << "\n";

    file << Obj(4, 0) << "   " << Obj(4, 1) << "   " << Obj(4, 2) << "\n";

    file << Obj(0, 0) << "   " << Obj(0, 1) << "   " << Obj(0, 2) << "\n";

    file << Obj(1, 0) << "   " << Obj(1, 1) << "   " << Obj(1, 2) << "\n";
    file << Obj(5, 0) << "   " << Obj(5, 1) << "   " << Obj(5, 2) << "\n";

    file << Obj(6, 0) << "   " << Obj(6, 1) << "   " << Obj(6, 2) << "\n";
    file << Obj(2, 0) << "   " << Obj(2, 1) << "   " << Obj(2, 2) << "\n";

    file << Obj(3, 0) << "   " << Obj(3, 1) << "   " << Obj(3, 2) << "\n";
    file << Obj(7, 0) << "   " << Obj(7, 1) << "   " << Obj(7, 2) << "\n";

    file << "------------------------------------------\n" << Obj << "\n";

    file.close();

    return !file.fail();
}