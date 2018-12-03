#include "a.h"
#include <iostream>

A::A() : p(new int[10]) {
    std::cout<<"construction of A begins" << std::endl;
    throw std::exception();
    std::cout<<"construction of A finished" << std::endl;
}

A::~A() {
    std::cout<<"destruction of A begins" << std::endl;
    delete[] p;
    std::cout<<"destruction of A finished" << std::endl;
}

B::B()
    try
    : p(new int[10])
    {
        std::cout<<"construction of B begins" << std::endl;
        throw std::exception();
        std::cout<<"construction of B finished" << std::endl;
    }
    catch (...) {
        std::cout << "Got an exception in B constructor!" << std::endl;
        if (p) {
            std::cout << "clearing the data after construction failed" << std::endl;
            delete[] p;
        }
    }

B::~B()
    try {
        std::cout<<"destruction of B begins" << std::endl;
        throw std::exception();
        delete[] p;
        std::cout<<"destruction of B finished" << std::endl;
    }
    catch (...) {
        std::cout << "Got an exception in B destructor!" << std::endl;
        if (p) {
            std::cout << "clearing the data after destruction failed..." << std::endl;
            delete[] p;
        }
    }
