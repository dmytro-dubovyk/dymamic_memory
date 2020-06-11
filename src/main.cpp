#include "a.h"

#include <iostream>

constexpr size_t kSize = 10000;

void stackOverFlow() {
    int a;
    stackOverFlow();
}

int* f() {
    return new int(1);
}

int main() {
    double* array[kSize];

    try {
        for (size_t i = 0; i < kSize; i++) {
            array[i] = new double[100];
            delete[] array[i];
        }
    } catch (std::bad_alloc e) {
        std::cout << "Got an exception: " << e.what() << std::endl;
    }

    //A* a{nullptr};
    try {
        A a;
        //a = new A();
        //throw std::exception();
    } catch (...) {
        std::cout << "Got an exception!" << std::endl;
        /*std::cout << "a == nullptr? " << (a == nullptr ? "true" : "false") << std::endl;
        if (a) {
            delete a;
        }*/
    }
    
    B* b{nullptr};
    try {
        b = new B();
    } catch (...) {
        std::cout << "Got an exception in constructor!" << std::endl;
        std::cout << "b == nullptr? " << (b == nullptr ? "true" : "false") << std::endl;
    }

    delete f();
    int* p = new int(1);
    int* p2 = p;
    delete p;
    //p = nullptr;
    delete p2;

    //stackOverFlow();

    std::cout<< "exiting programm" << std::endl;
}
