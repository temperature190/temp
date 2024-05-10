#include <iostream>

using std::cout;
using std::endl;

class FriendClass; // the definition of a friend class

class Point{
private:
    const int _x;
    int _y;
    int &_z = _y; // reference initialized at declaration of class
    int &_w = _z;// reference to reference
    int &_h;
    const int *_p = &_x;
    static int _count; // static variable
public:
    // in class constructor: all members must be initialized before curly braces - that's why we have initialization-list
    Point(int x, int y): _x(x), _y(y), _h(_y){_count++;} // non-initialized reference must be initialized at initialization-list
    explicit Point(char c): _x(3), _h(_y), _w(_y) { _y = 5; _count++;} // reference assignment is changed at initialization-list - OK

    Point(): Point(3, 3){} // delegation: object is initialized(and all of its members) at initialization list
    explicit Point(int z); // (delegation used)
    static int get_count() { return _count;} // static function doesn't manipulate non-static variables

    int get_x() const{ return _x;}
    const int *get_pointer() {_y++; return _p;}

    friend FriendClass; //  declaring FriendClass as a friend -> now it would have access to Point class just like a friend function
};

class FriendClass
{
    FriendClass(Point friend_point){
        int x = friend_point._x; // FriendClass has access to Point class
    }
};


Point::Point(int z): Point(z, z) { // no need to update count because constructor Point(int, int) was called
    cout << "hello" << endl;
}
int Point::_count = 0;
int remain()
{
}