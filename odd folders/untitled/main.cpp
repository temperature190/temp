#include <iostream>
#include <fstream>
#include <string>
int main()
{
    using std::cout;

    using std::fstream;
    using std::ifstream;
    using std::ofstream;
    using std::string;
    using std::ios;

    fstream in("in.txt", ios::in|ios::out);
    string line = "next";
    in << line;
    in >> line;
//    int loc = (int)in.tellg();
//    cout << loc;
    cout << line;
    in.close();
}