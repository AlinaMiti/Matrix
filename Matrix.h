#include "Vector.h"
#include <stdlib.h>
#include <random>

template<typename T>
class Matrix{
private:
    Vector<T>* _vectors;
    size_t _size;
public:
    Matrix() = delete; //удаление констр. по умолчанию

    Matrix(size_t rows, size_t cols){
        _size = rows;
        //Можно ли указать конкретный конструктор при создании массива
        _vectors = new Vector<T>[_size];
        for (size_t i = 0; i < _size; i++)
            _vectors[i] = Vector<T>(cols);
    }

    void Random(){
        for (size_t i = 0; i < _size; i++){
            for (size_t j = 0; j < _vectors->SizeCols(); j++){
                _vectors[i][j] = rand() % 10;
            }
        }
    }

    ~Matrix(){
        delete [] _vectors;
    }

    const Vector<T>& operator[](int index) const{  //для константной матрицы
        return _vectors[index];
    }

    Vector<T>& operator[](int index){
        return _vectors[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matr){
        for(size_t i = 0; i < matr._size; i++){
            os << matr._vectors[i] << std::endl;
        }
        return os;
    }

    double Determinant()const{
        double det = 0;
        if (_size != _vectors->SizeCols()){
            std::cout << "Error" << std::endl;
            exit;
        }
        if (_size == 1)
            return _vectors[0][0];
        else if (_size == 2)
            return _vectors[0][0] * _vectors[1][1] - _vectors[0][1] * _vectors[1][0];
        else{
            int det = 0;
            for (size_t k = 0; k < _size; k++){
                Matrix<int> New = Matrix<int>(_size - 1, _size - 1);
                for (size_t i = 0; i < _size; i++){
                    size_t t = 0;
                    for (size_t j = 0; j < _size; j++){
                        if (j == k)
                            continue;
                        New[i-1][t] = _vectors[i][j];
                        t++;
                    }
                }
                det += pow(-1, k + 2) * _vectors[0][k] * New.Determinant();
            }
            return det;
        }  
    }

    Matrix operator+(const Matrix& tmp)const{
        Matrix result = Matrix(_size, _vectors->SizeCols());
        if (_size != tmp._size || _vectors->SizeCols() != tmp._vectors->SizeCols()){
            std::cout << "Error" << std::endl;
            exit;
        }
        for (size_t i = 0; i < _size; i++) {
            for (size_t j = 0; j < _vectors->SizeCols(); j++) {
                result[i][j] = _vectors[i][j] + tmp._vectors[i][j];
            }
        }
        return result;
        }
    Matrix operator-(const Matrix& tmp)const{
        Matrix result = Matrix(_size, _vectors->SizeCols());
        if (_size != tmp._size || _vectors->SizeCols() != tmp._vectors->SizeCols()){
            std::cout << "Error" << std::endl;
            exit;
        }
        for (size_t i = 0; i < _size; i++) {
            for (size_t j = 0; j < _vectors->SizeCols(); j++) {
                result[i][j] = _vectors[i][j] - tmp._vectors[i][j];
            }
        }
        return result;
        }
    Matrix operator*(const Matrix& tmp)const{
        Matrix result = Matrix(_size, tmp._vectors->SizeCols());
        if ( _vectors->SizeCols() != tmp._size){
            std::cout << "Error" << std::endl;
            exit;
        }
        for (size_t i = 0; i < _size; i++) {
            for (size_t j = 0; j < tmp._vectors->SizeCols(); j++) {
                size_t cols = 0;
                size_t rows = 0;
                while (cols < _size || rows < tmp._vectors->SizeCols())
                {
                    result[i][j] += _vectors[i][rows] * tmp._vectors[cols][j];
                    cols++;
                    rows++;
                }
              
            }
        }
        return result;
        }
};