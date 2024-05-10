#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::pair;
using std::string;
using std::swap;
using std::ostream;

class A{
protected:
    int a;
    string s;

public:
    A(): a(1), s("A"){
        cout << "A def-ctr\n";
    }

    A(const A &a): a(a.a), s(a.s){
        cout << "A cpy-ctr\n";
    }

    A(int _a, const string &_s){
        a = _a;
        s = _s;
    }

    A &operator=(A &other){
        cout << "A asgn-op";
        if(this != &other){
            cout << "\n";
            swap(a, other.a);
            swap(s, other.s);
        }
        cout << ": self assignment\n";
        return *this;
    }

    friend ostream &operator<<(ostream &os, const A &a){
        os << "B printing:\n";
        os << "\ta: " << a.a << "\n";
        os << "\ts: " << a.s << "\n";
    }

    ~A(){
        cout << "A dtr\n";
    }
};

class B: public A{
public:
    int b = 5;
    B(): b(2){
        cout << "B def-ctr\n";
        a = 0;
        s = "B";
    }

    explicit B(int _b): b(_b){
        cout << "B int-ctr\n";
        a = 1;
        s = "B({_b})";
    }

    B(const B &other): b(other.b), A(other) {
        cout << "B cpy-ctr B\n";
    }

//    B(const A &other): b(2){
//        cout << "B cpy-ctr A\n";
//        a = -1;
//        s = "B(A)";
//    }

    ~B(){
        cout << "B dtr\n";
    }

    B &operator=(B &other){
        cout << "B asgn-op B";
        if(this != &other){
            cout << "\n";
            swap(a, other.a);
            swap(b, other.b);
            swap(s, other.s);
        }
        cout << ": self assignment\n";
        return *this;
    }

//    B &operator=(A &other){
//        cout << "B asgn-op";
//        if(this != &other){
//            cout << "\n";
//            swap(a, other.a);
//            swap(b, other.b);
//            swap(s, other.s);
//        }
//        cout << ": self assignment\n";
//        return *this;
//    }

    friend ostream &operator<<(ostream &os, const B &_b){
        os << "B printing:\n";
        os << "\tb: " << _b.b << "\n";
        os << "\ta: " << _b.a << "\n";
        os << "\ts: " << _b.s << "\n";
    }

    static int Become(){
        cout << "Becoming\n";
        return 0;
    }
};
int main(){
    /*test 1*/
    B b(3);
    cout << "###\n";
    A a(b);
    cout << "###\n";
    cout << a;

    /*test 2*/
//    B b;
//    B b1 = b;

    /*test 3*/
//    int x = 3;
//    int y = x += 2;
//    cout << y;
//    return 0;
}