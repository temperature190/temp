#include <iostream>
#include <utility>
#include "main.h"

using std::cout;
using std::endl;
using std::string;



//class B: A{
//private:
//    string name_;
//public:
//    explicit B(string const &name): name_(name) {cout << "constructing B: " << name << endl;}
//};

int main() {
    string arch = "name";
    A a(arch);
}

A::A(string name):name_(std::move(name)) {}
