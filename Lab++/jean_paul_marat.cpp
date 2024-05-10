//
// Created by aran on 28/08/22.
//
#include <iostream>
#include <cstring>
#include "main.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

// printer function for debugging
ostream &MyString::operator<<(ostream &s){
    s << this->_string << "\n";
    return s;
}

istream &MyString::operator>>(istream &s){
    s >> this->_string;
    return s;
}

// DEMO 1
MyString::MyString(const char *str) {
    _length = (int)strlen(str) + 1; // do not use strlen and strcpy(reserved for C)
    _string = new char[_length];
    strcpy(_string, str);
}

MyString::~MyString() {
    delete [] _string;
}

// DEMO 2
//MyString &MyString::operator=(MyString const &rhs){ // remember to handle self-assignment
//    if(this != &rhs) { // handle self-assignment:  nothing happens
//        char *old_string = _string; // remember pointer if allocation fails
//
//        try {
//            _string = new char[rhs._length]; // this is where it will except
//            delete [] old_string;
//            strcpy(_string, rhs._string);
//            _length = rhs._length;
//        }
//        catch(const std::bad_alloc &ba){ //  allocation failed
//            cout << "Allocation failed: (copy-assignment)\n";
//            _string = old_string; // get back the pointer
//        }
//    }
//    return *this;
//}

// DEMO 3.1
void do_nothing(const MyString rhs){}

MyString::MyString(const MyString &rhs) { // if no initializer-list - default values are given
//    this->operator=(rhs); // this wont work because old string will be deleted, but this is a constructor, so it was never allocated

    try {
        _string = new char[rhs._length]; // this is where it will except
        strcpy(_string, rhs._string);
        _length = rhs._length;
    }
    catch (const std::bad_alloc &ba) { //  allocation failed - _string and _length will be null
        cout << "Allocation failed: (copy-constructor)\n";
    }
}

// DEMO 3.2 - 2nd option - we cant outsource ctr to operator=, so we outsource operator= to ctr

void MyString::swap(MyString *other){ // inner values are swapped with std::swap
    std::swap(_string, other->_string);
    std::swap(_length, other->_length);
}

MyString &MyString::operator=(MyString rhs){ // copy by value - rhs is a deep copy
    swap(&rhs);
    return *this;
} // rhs is destroyed

int main() {
    // DEMO 1
//    MyString str1((char *)"Foo");
//    MyString str2((char *)"Bar");
//    str1 = str2; // defualt copy-assignment uses shallow copy -> double free and memory leak

    // DEMO 2 - write our own copy-assignment
    // TODO: When input is more than one character, this fails valgrind with invalid reads and invalid writes, fixed once char* is converted to string type
//    str1 = str2;
//    str2 << (str1 << cout); // the binary operation << is always to the right of the object(like a funciton)
//    str1 >> cin;
//    str2 << (str1 << cout);

    // DEMO 3 - default copy-constructor uses shallow-copy -> double free :: write our own copy-ctr
//    MyString s("foo");
//    do_nothing(s);
}
#include "jean_paul_marat.h"
