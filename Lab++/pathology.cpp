//
// Created by aran on 28/08/22.
//

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Complex{
private:
    int _real;
    int _imaginary;
public:
    Complex(int real, int imaginary): _real(real), _imaginary(imaginary){}
//    Complex(){cout << "def ctr\n";} // if members are not initialized then they are junk
    Complex(): Complex(0, 0){cout << "ctr\n";}
    Complex(Complex &rhs): _real(rhs._real), _imaginary(rhs._imaginary){cout << "copy-ctr\n";} // this is the copy-ctr
    ~Complex(){cout << "dtr\n";};
    // methods
    int get_real() const{return _real;}
    int get_imaginary() const{return _imaginary;}
    void set_real(int real){_real = real;}

    //operators
    Complex &operator=(Complex const &rhs){
        _real = rhs._real;
        _imaginary = rhs._imaginary;
        cout << "copy-assignment operator\n";
        return *this;
    }
};
// TEST FUNC 1
void function_Accepting_complex_argument(Complex c){ // copy-ctr is called
    cout << "\t" << c.get_real() << "\n\t";
    c.set_real(3);
} // Complex dtr is called

// TEST FUNC 2
Complex returns_complex_by_value(){
    cout << "func begin\n";
    Complex x(1, 3);
    cout << "_x created\n\n";
    return x; // here copy-ctr is called and also dtr is called because the scope ends
}

int main(){
    Complex a; // def ctr is called
//    Complex a_1 = a; // this calls copy-ctr because of the initialization and because there is no copy-ctr so def ctr is called
//    Complex b(a); // this calls the copy-ctr, and if there isn't one then def-ctr is called
//    Complex c(2, 5);
//    Complex d(7, 8);

// DEMO 1
//    cout << a.get_real();
//    cout << a.get_imaginary() << endl;

// DEMO 2
//    a = b; // this call the copy-assignment operator
//    (b = d) = c; // chained copy-assignment
//
//    cout << b.get_real();
//    cout << b.get_imaginary() << endl;

// TEST FUNC 1
//    cout << "function accepting complex argument\n\t";
//    function_Accepting_complex_argument(a);
//    cout << "end of function(faca)\n";

// TEST FUNC 2
//    cout << "func\n";
//    a = returns_complex_by_value();
//    cout << "func end\n\n";
}
#include "pathology.h"
