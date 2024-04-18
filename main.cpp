#include <iostream>
#include "Matrix.h" //там есть Vector.h и он автоматом подключит


int main(){
    /*double* array_for_vec2 = new double[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    Vector<double> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Vector<double> vec3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << vec3 << std::endl;
    std::cout << vec2 << std::endl;
    auto rez = vec3 + vec2;
    std::cout << rez;
    delete [] array_for_vec2;
    */
    
    int arr[] = {1, 3, 4, 6, 8};
    int arr2[] = {2, 10, 10, 7, 20};

    Vector<int> vec1 = Vector<int>(5, arr);
    Vector<int> vec2 = Vector<int>(5, arr2);
    //std::cout << vec1 + vec2 << std::endl;
    //std::cout << vec1 - vec2 << std::endl;
    //std::cout << vec1 * vec2 << std::endl;
    
    //std::cout << "Dlina = " << vec2.Dlina() << std::endl;
    //vec2.Normal();
    //std::cout << vec2 << std::endl;

    Matrix<int> matrix = Matrix<int>(3, 3);
    matrix.Random();
    Matrix<int> matrix2 = Matrix<int>(3, 2);
    matrix2.Random();
    Matrix<int> result = matrix + matrix2;
    //std::cout << result << std::endl;
    std::cout << matrix << std::endl;
    int det = matrix.Determinant();
    
    std::cout << det << std::endl;
    //std::cout << matrix2 << std::endl;
    Matrix<int> matrix12 = matrix * matrix2;
    //std::cout << matrix12  << std::endl;
    

    return 0;
}