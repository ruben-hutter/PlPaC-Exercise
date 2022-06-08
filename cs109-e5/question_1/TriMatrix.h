#ifndef TriMatrix
#define TriMatrix

class Complex {
    double real;
    double imaginary;

    public:
        Complex(double real, double imaginary);
        Complex();
        void add(Complex num);
        void multiply(Complex num);
        void print(); 
};

class triMatrix {
    int size;
    Complex** arr;

    public:
        triMatrix(int size, Complex data[]);
        triMatrix(int size);
        ~triMatrix();
        triMatrix* transposed();
        triMatrix operator*(triMatrix& right);
        triMatrix operator+(triMatrix& right);
        triMatrix operator+=(triMatrix& right);
        void printArray();
};

#endif