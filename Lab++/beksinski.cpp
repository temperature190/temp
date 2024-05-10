//
// Created by aran on 08/09/22.
//

#include "beksinski.h"
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

#define HASH_START 17
#define RES_MULT 31


using std::cout;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::make_unique;
using std::ostream;
using std::vector;

class Node{
private:
    shared_ptr<int> _data = make_shared<int>();
    unique_ptr<string> _box;
//    shared_ptr<Node> _next = make_shared<Node>();
public:
    Node()=default;
    Node(int data, string *box): _box(box){
        *_data = data;
    }
    explicit Node(int data): _box(make_unique<string>()){*_data = data;}
    explicit Node(unique_ptr<string> &box): _box(std::move(box)){};
    Node(const Node &other){ // cpy-ctr
        _data = other._data;
        _box = make_unique<string>();
//        _next = other._next;
    }

    string get_box() const{return *_box;}
    void operator[](int data) const{*_data = data;}
    int operator()() const{return *_data;}
    Node &operator=(const Node &rhs){
        if(this != &rhs) {
            *_data = *rhs._data;
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, const Node &node){
        cout << node() << *node._box << "\n";
        return out;
    }
    friend bool operator<(const Node &a, const Node &b){return a() < b();}
};
unique_ptr<string> get_up(){
    auto up = make_unique<string>("sky");
    return up;
}
int main(){
    unique_ptr<string> sand = get_up();
    Node node(sand);
    cout << node;
    cout << *sand;
    return 0;
}
