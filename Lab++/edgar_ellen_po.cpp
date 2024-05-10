//
// Created by aran on 11/09/22.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <unordered_map>
#include <set>

using std::vector;
using std::cout;
using std::map;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::ostream;
using std::unordered_map;
using std::set;

class Node{
private:
    shared_ptr<int> _data = make_shared<int>();
//    shared_ptr<Node> _next = make_shared<Node>();
public:
    Node() = default;
    explicit Node(int data){*_data = data;}
    Node(const Node &other){ // cpy-ctr
        _data = other._data;
//        _next = other._next;
    }

    void operator[](int data) const{*_data = data;}
    int operator()() const{return *_data;}
    Node &operator=(const Node &rhs){
        if(this != &rhs) {
            *_data = *rhs._data;
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, const Node &node){
        cout << node();
        return out;
    }
    friend bool operator<(const Node &a, const Node &b){return a() < b();}
};

class Toy{
private:
    Node *arrow = new Node[2];
public:
    Toy(){
        *arrow = (Node)3;
    }
    ~Toy(){
        delete [] arrow;
    }
};

class ToyNode{
private:
    shared_ptr<ToyNode> _next;
public:
    ToyNode(){
        _next = make_shared<ToyNode>();
    }
    void set_next(ToyNode *next){
        _next = static_cast<const shared_ptr<ToyNode>>(next);
    }
};
int main(){
//    std::pair<string, int> *arr = new std::pair<string, int>[5];
//    for(const auto &b: arr){
//
//    }

    ToyNode n1, n2, n3;
    n1.set_next(&n2);
    n2.set_next(&n3);
}