#include "TriMatrix.h"
#include <iostream>

Complex::Complex(double real, double imaginary) {
    this->real = real;
    this-> imaginary = imaginary;
}
Complex::Complex() {
    real = 0;
    imaginary = 0;
}
void Complex::add(Complex num) {
    this->real = this->real + num.real;
    this->imaginary = this->imaginary + num.imaginary;
}
void Complex::multiply(Complex num) {
    real = real*num.real - imaginary*num.imaginary;
    imaginary = real*num.imaginary + num.real * imaginary;
}
void Complex::print() {
    std::cout << real << " + " << imaginary << "i";
}

triMatrix::triMatrix(int size, Complex* data) {
    this->size = size;
    arr = new Complex*[size];
    for (int i = 0; i < size; i++) {
        arr[i] = new Complex[size];
    }

    int counter = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i+1; j++) {
            arr[i][j] = data[counter];
            counter++;
        }
    }
}
triMatrix::triMatrix(int size) {
    this->size = size;
    arr = new Complex*[size];
    for (int i = 0; i < size; i++) {
        arr[i] = new Complex[size];
    }
}
triMatrix::~triMatrix() {
    for (int i = 0; i < size; i++) {
        delete [] arr[i]; 
    }
    delete [] arr;
}
triMatrix* triMatrix::transposed() {
    triMatrix* transposedMatrix = new triMatrix(this->size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i+1; j++) {
            transposedMatrix->arr[j][i] = arr[i][j];
        }
    }
    return transposedMatrix;
}
//Operator sind cringe
void triMatrix::printArray() {
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j].print();
            std::cout << ", ";
        }
        std::cout << "\n";
    }
}

int main() {
    Complex list [] = {Complex(1.2, 0.2),
            Complex(3.2, -0.2), Complex(12.4, 0),
            Complex(0, 0), Complex(5.4, 0), Complex(4.3, 0),
            Complex(12.2, 2.1), Complex(-4.3, 0), Complex(3.2, -0.3), Complex(5.5, 0),
            Complex(8.7, 3.0), Complex(6.5, 0), Complex(1.0, 0), Complex(-3.2, 0), Complex(4.3, 0)};
    triMatrix *a = new triMatrix(5, list);
    a->printArray();
    triMatrix *b = a->transposed();
    b->printArray();
}