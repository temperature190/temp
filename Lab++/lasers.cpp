//
// Created by aran on 28/08/22.
//
#include "lasers.h"

#include <iostream>

using std::cout;
using std::endl;
using std::fstream;
using std::ostream;
using std::istream;
using std::string;

class Test {
private:
    int _val;
    int &_ref_to_val = _val;
public:
    // constructors
    explicit Test(int val) : _val(val) { cout << val << endl; }

    // methods
    int &get_val() const { return _ref_to_val; }

    bool operator<(const Test &rhs) const {
        return this->_val < rhs._val;
    }

    bool operator==(const Test &rhs) const {
        return this->_val == rhs._val;
    }

    Test &operator+=(const Test &rhs) {
        this->_val += rhs._val;
        return *this;
    }

    Test &operator-=(const Test &rhs) {
        this->_val -= rhs._val;
        return *this;
    }

    Test &operator++() {
        this->_val++;
        return *this;
    }

    Test &operator--() {
        this->_val--;
        return *this;
    }

    Test operator++(int) {
        Test temp = *this;
        this->_val++;
        return temp;
    }

    Test operator--(int) {
        Test temp = *this;
        this->_val--;
        return temp;
    }

    friend ostream &operator<<(ostream &s, const Test &t);

    friend istream &operator>>(istream &s, Test &t);
};

ostream &operator<<(ostream &s, const Test &t){
    s << t._val;
    return s;
}

istream &operator>>(istream &s, Test &t){
    s >> t._val;
    return s;
}

#include <map>
using std::cout;
using std::cin;
using std::string;
using std::map;

int count_word_freq() {
    map<string, int> freq;
    string word;
    while (cin >> word) {
        freq[word]++;
    }

    for (auto &item: freq) {
        cout << item.first << item.second << "\n";
    }
}