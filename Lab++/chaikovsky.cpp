//
// Created by aran on 08/09/22.
//
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
using std::ostream;
using std::vector;

class Node{
private:
    shared_ptr<int> _data = make_shared<int>();
//    shared_ptr<Node> _next = make_shared<Node>();
public:
    Node()=default;
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


typedef shared_ptr<Node> sp_node;
typedef std::size_t (*hash_func)(const sp_node& n1);
typedef bool (*equal_func)(const sp_node& n1,const sp_node& n2);

typedef std::unordered_map<sp_node, double, hash_func,equal_func> rank_map; // typedef map

std::size_t node_hash(const sp_node &node){
    return 10;
}
bool node_equal(const sp_node &n1, const sp_node &n2){
    return !(*n1 < *n2) && !(*n2 < *n1);
}

int main(){
    Node nodes[] = {Node(1), Node(2), Node(5), Node(3), Node(7), Node(0)};

//    std::unordered_map<sp_node, double, hash_func, equal_func> ranks;
    rank_map ranks(0, node_hash, node_equal);
//    std::unordered_map<sp_node, double, hash_func, equal_func> ranks(0, node_hash, node_equal);
//    rank_map ranks;
    sp_node x[10];
    double i = 1;
    int j = 0;
    for(const auto &node: nodes) {
        x[j] = make_shared<Node>(node);
        ranks[x[j]] = i;
        j++;
        i *= 1.1;
    }
    return 0;
}