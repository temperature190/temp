#ifndef UNTITLED1_MAIN_H

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class A{
private:
    string name_;
public:
    explicit A(string name);
    A(A const &a):name_(a.name_);
    ~A();
};

#define UNTITLED1_MAIN_H

#endif //UNTITLED1_MAIN_H
