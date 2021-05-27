#include "../include/Matrix.hh"


template <unsigned int Size>
Matrix<Size>::Matrix() {

    for (int i = 0; i < Size; ++i) {

        for (int j = 0; j < Size; ++j) {

            value[i][j] = 0;

        }

    }

}

template <unsigned int Size>
Matrix<Size>::Matrix(double tmp[Size][Size]) {

    for (unsigned int i = 0; i < Size; ++i) {

        for (unsigned int j = 0; j < Size; ++j) {

            value[i][j] = tmp[i][j];

        }

    }

}

template <unsigned int Size>
Vector<Size> Matrix<Size>::operator * (Vector<Size> tmp) {
    Vector<Size> result;

    for (unsigned int i = 0; i < Size; ++i) {

        for (unsigned int j = 0; j < Size; ++j) {

            result[i] += value[i][j] * tmp[j];

        }

    }

    return result;

}

template <unsigned int Size>
Matrix<Size> Matrix<Size>::operator + (Matrix<Size> tmp) {
    Matrix result;

    for (unsigned int i = 0; i < Size; ++i) {

        for (unsigned int j = 0; j < Size; ++j) {

            result(i, j) = this->value[i][j] + tmp(i, j);

        }

    }

    return result;

}

template <unsigned int Size>
Matrix<Size> Matrix<Size>::operator * (const Matrix<Size> tmp) {
    Matrix<Size> result;

    for (unsigned int i = 0; i < Size; ++i) {

        for (unsigned int j = 0; j < Size; ++j) {

            for (int k = 0; k < Size; ++k) {

                result.value[i][j] += value[i][k] * tmp.value[k][j];

            }

        }

    }

    return result;

}

template <unsigned int Size>
double &Matrix<Size>::operator()(unsigned int row, unsigned int column) {

    if (row >= Size) {
 
        std::runtime_error("Error: The Matrix is out of range");

    }

    if (column >= Size) {

        std::runtime_error("Error: The Matrix is out of range");

    }

    return value[row][column];

}

template <unsigned int Size>
const double &Matrix<Size>::operator () (unsigned int row, unsigned int column) const {

    if (row >= Size) {
        
        std::runtime_error("Error: The Matrix is out of range");

    }

    if (column >= Size) {
        
        std::runtime_error("Error: The Matrix is out of range");
        
    }

    return value[row][column];
}

template <unsigned int Size>
bool Matrix<Size>::operator == (const Matrix<Size> tmp) {

    for(unsigned int i = 0; i < Size; ++i) {

        for(unsigned int j = 0; j < Size; ++j) {

            if(!(value[i][j] >= tmp(i, j) - MAX_DIFF && value[i][j] <= tmp(i, j) + MAX_DIFF)) return false;

        }

    }

    return true;

}

template <unsigned int Size>
std::istream &operator>>(std::istream &in, Matrix<Size> &mat) {

    for (int i = 0; i < Size; ++i) {

        for (int j = 0; j < Size; ++j) {

            in >> mat(i, j);

        }

    }

    return in;

}

template <unsigned int Size>
std::ostream &operator<<(std::ostream &out, const Matrix<Size> &mat) {

    for (int i = 0; i < SIZE; ++i) {

        for (int j = 0; j < SIZE; ++j) {

            out << "| " << mat(i, j) << " | ";

        }

        std::cout << std::endl;

    }

    return out;

}