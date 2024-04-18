#include <iostream>
#include <math.h>

template<typename T>   //абстрактный тип данных
class Vector{
private:
    T* _array;
    size_t _size;
    double* _norm;
public:
    Vector(){
        _size = 10;
        _array = new T[_size];
        _norm = new double[_size];
    }

    Vector(const Vector& tmp){               //конструктор копирования
        _size = tmp._size;
        _array = new T[_size];
        _norm = new double[_size];
        for (size_t i = 0; i < _size; i++){  //i типа size_t, т.к. мы сравниваем с _size этого же типа
            _array[i] = tmp._array[i];
            _norm[i] = static_cast<double>(tmp._array[i]);
        }
    }

    size_t SizeCols(){
        return _size;
    }

    T& operator[](int i){
        return _array[i];
    }

    Vector(std::initializer_list<T> list){
        _size = list.size();
        _array = new T[_size];
        _norm = new double[_size];
        int i = 0;
        for (auto elem = list.begin(); elem != list.end(); elem++, i++){
            _array[i] = *elem;
        }
        for (size_t i = 0; i < _size; i++){
            _norm[i] = static_cast<double>(_array[i]);
        }
    }

    Vector(size_t size, T* array){
        _size = size;
        _array = new T[_size];
        for (int i = 0; i < size; i++){
            _array[i] = array[i];
        }
        _norm = new double[_size];
        for (int i = 0; i < size; i++){
            _norm[i] = static_cast<double>(_array[i]);
        }
    }
    Vector(size_t size): _size(size), _array(new T[size]), _norm(new double[size]){
        for (int i =0; i < size; i++){
            _array[i] = 0;
            _norm[i] = 0;
        }
    }
    ~Vector(){
        delete [] _array;
        delete [] _norm;
    }

    //1. Что если tmp._size < _size ???
    //2. Нужно ли создавать копии?
    //3. Чего не хватает? Когда присваивание лишнее?
    Vector& operator=(const Vector& tmp){
        if (tmp._size > _size){
            delete [] _array;
            _array = new T[tmp._size];   
        }
        _size = tmp._size;
        for (size_t i = 0; i < _size; i++)
            _array[i] = tmp._array[i];
        return *this;
    }

    friend std::ostream& operator<< (std::ostream& os, const Vector<T>& vec){
        os << "(";
        for (int i =0; i < vec._size; i++){
            os << vec._array[i];
            if (i + 1 != vec._size)
                os << ", ";
        }
        os << ")";
    return os;
    }

    //перегрузки
    Vector operator+(const Vector& vec) const{
        T* rez = new T[_size];
        for (size_t i = 0; i < _size; i++){
            rez[i] = _array[i] + vec._array[i];
        }
        Vector A = Vector(_size, rez);
        delete [] rez;
        return A;
    }
    Vector operator-(const Vector& vec) const{
        T* rez = new T[_size];
        for (size_t i = 0; i < _size; i++){
            rez[i] = _array[i] - vec._array[i];
        }
        Vector A = Vector(_size, rez);
        delete [] rez;
        return A;
    }
    double operator*(const Vector& vec) const{  
        double rez;
        for (size_t i = 0; i < _size; i++){
            rez += _array[i] * vec._array[i];
        }
        return rez;
    }

    void Normal(){
        double Dl = Dlina();
        
        for (size_t i = 0; i < _size; i++){
            _norm[i] = _array[i]/Dl;
        }
        std::cout << "(";
        for(size_t i = 0; i < _size ; i++){
            std::cout << _norm[i] << ", ";
        }
        
        std::cout << " )";
    }
    double Dlina(){
        double summ = 0;
        for (size_t i = 0; i < _size; i++){
            summ += pow(_array[i],2);
        } 
        summ = sqrt(summ);
        return summ;
    }
};