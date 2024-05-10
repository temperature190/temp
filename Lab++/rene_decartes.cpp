//
// Created by aran on 11/09/22.
//

#include "rene_decartes.hpp"
#include "arthur_miller.h"
#include <iostream>
#include <map>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ostream;
using std::istream;
using std::pair;

class Node{
public:
    void *_data = nullptr;
    Node *_next = nullptr;

    Node() = default; // def-ctr
    Node(const Node &other){ // cpy-ctr
        _data = new int;
        *(int *)_data = *((int *)other._data);
        (*(int *)_data)+=2;
        cout << "node:" << this << ": " <<  *(int *)_data << " cpy-ctr\n";
    }
    ~Node(){
        cout << "node:" << this <<  " destructor: ";
        if(_next){delete _next;}
        if(_data){cout << *(int *)_data; delete (int *)_data;}
        cout << "\n";
    }
    explicit Node(int data){
        cout << "node:" << this << ": " << data << " data-ctr\n";
        _data = new int;
        *(int *)_data = data;
    }
    Node &operator=(Node rhs){
        if(this != &rhs) {
            std::swap(_data, rhs._data);
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, const Node &node){
        cout << &node << ": " << *(int *)node._data << "\n";
        return out;
    }
    friend bool operator<(const Node &a, const Node &b){return *(int *)a._data < *(int *)b._data;}
//    bool operator<(const Node &other){return *(int *)_data < *(int *)other._data;}

};

class LinkedList{
private:
    Node *_first;
    Node *_last;
    size_t _size;

    class Iterator{
    public:
        Node *_pointer;

        Iterator(){_pointer = nullptr;}
        explicit Iterator(Node &node){_pointer = &node;}
        void operator++(int) {_pointer = _pointer->_next;} // postfix
        void operator++(){(*this)++;} // prefix
        Node &operator*() const{return *_pointer;}
        Node *operator->() const{return _pointer;}
        bool operator==(const Iterator &other) const{return _pointer == other._pointer;}
        bool operator!=(const Iterator &other) const{return !((*this) == other);}
        friend int operator-(const Iterator &a, const Iterator &b){return *(int *)a._pointer->_data - *(int *)b._pointer->_data;}
        friend Iterator operator-(const Iterator &a, int b){return Iterator(*(a._pointer - b));}
        friend int operator+(const Iterator &a, const Iterator &b){return *(int *)a._pointer->_data + *(int *)b._pointer->_data;}
        friend Iterator operator+(const Iterator &a, int b){return Iterator(*(a._pointer + b));}
        friend bool operator<(const Iterator &a, const Iterator &b){return *(int *)(a->_data) < *(int *)(b->_data);}
    };

    class ReverseIterator{
    public:
        Node *_pointer;
        LinkedList *_list;

        ReverseIterator() = default;
        explicit ReverseIterator(LinkedList *list): _list(list), _pointer(list->_last){};
        void operator++(int) {
            for(const auto &iter: *_list){
                if(iter._next == _pointer){
                    _pointer = (Node *)iter._data; // fixme?
                }
            }
        } // postfix
        void operator++(){(*this)++;} // prefix
        Node &operator*() const{return *_pointer;}
        Node *operator->() const{return _pointer;}
//        friend void operator=(Iterator, )
        bool operator==(const Iterator &other) const{return _pointer == other._pointer;}
        bool operator!=(const Iterator &other) const{return !((*this) == other);}
    };

public:
    LinkedList(){
        cout << "linkedlist:" << " ctr\n";
        _first = nullptr;
        _last = nullptr;
        _size = 0;
    }
    ~LinkedList(){
        cout << "linkedlist:" << " dtr\n";
        cout << *this;
        if(_size != 0) {
            delete _first;
        }
    }
    void foo(){
        Iterator it(*_first);;
        cout << *(int *)(it->_data);
    }
    Node &append(const Node &other){
        Node *new_node = new Node(other);

        if(_size == 0){
            _first = _last = new_node;
            _size = 1;
            return *new_node;
        }

        _last->_next = new_node;
        _last = _last->_next;
        _size++;
        return *new_node;
    }
    const size_t &get_size() const{return _size;}

    // iterator methods
    Iterator begin() const{return Iterator(*_first);}
    Iterator end() const {Iterator end(*_last); ++end; return end;}

    friend ostream &operator<<(ostream &out, const LinkedList &list){
        for(const auto &node: list){
            out << "\t" << node;
        }
        out << endl;
        return out;
    }

};

int main(){
    cout << "line:1\n";
    LinkedList list;
    cout << "line:2\n";
    Node n1(1), n2(2);
    cout << "line:3\n";
    list.append(n1);
    cout << "line:4\n";
    list.append(n2);
    cout << n1;
    cout << n2;

    auto *scale = new pair<int *, Node>;
    int x = 3;
    scale->first = &x;
    scale->second = Node(4);
    delete scale;
}