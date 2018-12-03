#include <iostream>
#include "a.h"

int main(){
    constexpr size_t size = 10000;
    double* array[size];
    
    try {
        for (size_t i = 0; i < size; i++) {
            array[i] = new double[100];
            delete[] array[i];
        }
    } catch (std::bad_alloc e) {
        std::cout << "Got an exception: " << e.what() << std::endl;
    }

    try {
        A a;
        throw std::exception();
    } catch (...) {
        std::cout << "Got an exception!" << std::endl;
    }
    
    try {
        B b;
    } catch (...) {
        std::cout << "Got an exception!" << std::endl;
    }
    
    int* p = new int(1);
    delete p;
    //p = nullptr;
    delete p;
    std::cout<< "exiting programm" << std::endl;
}
