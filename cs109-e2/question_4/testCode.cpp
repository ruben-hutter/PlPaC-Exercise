#include "BSClass.h"
#include <cstdint>
#include "random"

void run_byte_test(BSClass<signed char> byte_list) {
    cout << "> TEST: Byte Test... ----------------" << endl;
    // init random gen
    std::default_random_engine dre((std::random_device())());
    std::uniform_int_distribution<signed char> uid(std::numeric_limits<signed char>::min(), std::numeric_limits<signed char>::max());
    // populate array with 100 random values
    for (int i = 0; i < 100; i++) {
        byte_list.add_elem(uid(dre));
    }
    // print
    byte_list.print();
    // sort
    byte_list.sort();
    // print
    cout << "> Sorted version: ----------------" << endl;
    byte_list.print();
    // change elements
    for (int i = 0; i < 100; i++) {
        switch(i%4) {
            case 0:
                byte_list.add(i, 101 - i);
                break;
            case 1:
                byte_list.subtract(i, 101 - i);
                break;
            case 2:
                byte_list.mult(i, 101 - i);
                break;
            case 3:
                byte_list.div(i, 101 - i);
                break;
        }

    }
    cout << "> After change version: ----------------" << endl;
    byte_list.print();
}

void run_int_test(BSClass<long long int> long_long_int_list) {
    cout << "> TEST: Long Long Int Test... ----------------" << endl;
    // init random gen
    std::default_random_engine dre((std::random_device())());
    std::uniform_int_distribution<long long int> uid(std::numeric_limits<long long int>::min(), std::numeric_limits<long long int>::max());
    // populate array with 100 random values
    for (int i = 0; i < 100; i++) {
        long_long_int_list.add_elem(uid(dre));
    }
    //print
    long_long_int_list.print();
    // sort
    long_long_int_list.sort();
    //print
    cout << "> Sorted version: ----------------" << endl;
    long_long_int_list.print();
    // change elements
    for (int i = 0; i < 100; i++) {
        switch(i%4) {
            case 0:
                long_long_int_list.add(i, 101 - i);
                break;
            case 1:
                long_long_int_list.subtract(i, 101 - i);
                break;
            case 2:
                long_long_int_list.mult(i, 101 - i);
                break;
            case 3:
                long_long_int_list.div(i, 101 - i);
                break;
        }

    }
    cout << "> After change version: ----------------" << endl;
    long_long_int_list.print();
}

void run_float_test(BSClass<float> float_list) {
    cout << "> TEST: Float Test... ----------------" << endl;
    // init random gen
    std::default_random_engine dre((std::random_device())());
    std::uniform_real_distribution<float> urd(0, 42.0);
    // populate array with 100 random values
    for (int i = 0; i < 100; i++) {
        float_list.add_elem(urd(dre));
    }
    // print
    float_list.print();
    // sort
    float_list.sort();
    // print
    cout << "> Sorted version: ----------------" << endl;
    float_list.print();
    // change elements
    for (int i = 0; i < 100; i++) {
        switch(i%4) {
            case 0:
                float_list.add(i, 101 - i);
                break;
            case 1:
                float_list.subtract(i, 101 - i);
                break;
            case 2:
                float_list.mult(i, 101 - i);
                break;
            case 3:
                float_list.div(i, 101 - i);
                break;
        }

    }
    cout << "> After change version: ----------------" << endl;
    float_list.print();
    
}

void run_long_double_test(BSClass<long double> double_long_list) {
    cout << "> TEST: Double Long Test... ----------------" << endl;
    // init random gen
    std::default_random_engine dre((std::random_device())());
    std::uniform_real_distribution<long double> urd(0, 42.0);
    // populate array with 100 random values
    for (int i = 0; i < 100; i++) {
        double_long_list.add_elem(urd(dre));
    }
    // print
    double_long_list.print();
    // sort
    double_long_list.sort();
    // print
    cout << "> Sorted version: ----------------" << endl;
    double_long_list.print();
    // change elements
    for (int i = 0; i < 100; i++) {
        switch(i%4) {
            case 0:
                double_long_list.add(i, 101 - i);
                break;
            case 1:
                double_long_list.subtract(i, 101 - i);
                break;
            case 2:
                double_long_list.mult(i, 101 - i);
                break;
            case 3:
                double_long_list.div(i, 101 - i);
                break;
        }

    }
    cout << "> After change version: ----------------" << endl;
    double_long_list.print();
}

int main() {
    // check byte
    BSClass<signed char> byte_list;
    run_byte_test(byte_list);
    // check long long int
    BSClass<long long int> long_long_int_list;
    run_int_test(long_long_int_list);
    // check float
    BSClass<float> float_list;
    run_float_test(float_list);
    // check long double
    BSClass<long double> long_double_list;
    run_long_double_test(long_double_list);
    return 0;
}