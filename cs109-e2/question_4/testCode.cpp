#include "BSClass.h"
#include <cstdint>
#include "random"

void run_byte_test(BSClass<int8_t> byte_list) {
    cout << "> TEST: Byte Test..." << endl;
    // init random gen
    std::default_random_engine dre((std::random_device())());
    std::uniform_int_distribution<int8_t> uid(INT8_MIN, INT8_MAX);
    // populate array with 100 random values
    for (int i = 0; i < 100; i++) {
        byte_list.add_elem(uid(dre));
    }
    // print
    byte_list.print();
    // sort
    byte_list.sort();
    // print
    cout << "Sorted version:" << endl;
    byte_list.print();
}

void run_int_test(BSClass<int64_t> int64_t_list) {
    cout << "> TEST: Int64_t Test..." << endl;
    // init random gen
    std::default_random_engine dre((std::random_device())());
    std::uniform_int_distribution<int8_t> uid(INT64_MIN, INT64_MAX);
    // populate array with 100 random values
    for (int i = 0; i < 100; i++) {
        int64_t_list.add_elem(uid(dre));
    }
    //print
    int64_t_list.print();
    // sort
    int64_t_list.sort();
    //print
    cout << "Sorted version:" << endl;
    int64_t_list.print();
}

void run_float_test(BSClass<float> float_list) {
    cout << "> TEST: Float Test..." << endl;
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
    cout << "Sorted version:" << endl;
    float_list.print();
}

void run_long_double_test(BSClass<long double> double_long_list) {
    cout << "> TEST: Double Long Test..." << endl;
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
    cout << "Sorted version:" << endl;
    double_long_list.print();
}

int main() {
    // check byte
    BSClass<int8_t> byte_list;
    // check long long int
    BSClass<int64_t> int64_t_list;
    // check float
    BSClass<float> float_list;
    // check long double
    BSClass<long double> double_long_list;
    return 0;
}