//
// Created by aran on 11/09/22.
//


#include <iostream>
#include <map>
#include <unordered_map>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ostream;
using std::istream;
using std::hash;
using std::unordered_map;

int main(){
    int *turtles = new int[5];
    for(int i = 0; i < 5; i++){
        turtles[i] = i;
    }
    for(int i = 0; i < 10; i++)
        cout << turtles[i] << " ";
    turtles = new int[10];
    for(int i = 0; i < 10; i++)
        cout << turtles[i] << " ";
    delete [] turtles;
}