#include <iostream>
#include <utility>
#include <fstream>

using std::string;
using std::pair;
using std::swap;
using std::istream;
using std::ifstream;

class Node{
    friend class BST;
    typedef pair<string, int> Data;

private:
    Data _data;
    Node *_left = nullptr;
    Node *_right = nullptr;

public:
    Node(): _data({"", 0}){}
    explicit Node(Data data): _data(std::move(data)){}
    Node(const Node &node): _data(node._data){}
    ~Node(){
        delete _right;
        delete _left;
    }

    Node &operator=(Node other){
        swap(_data, other._data);
        return *this;
    }
};

class BST{

private:
    Node *_head = nullptr;

public:
    BST()=default;
    BST(const BST &other){
        rec_build(&_head, other._head);
    }

    void rec_build(Node **temp, const Node *walk){
        if(walk == nullptr) return;

        *temp = new Node(walk->_data);
        rec_build(&((*temp)->_left), walk->_left);
        rec_build(&((*temp)->_right), walk->_right);
    }

    ~BST(){
        delete _head;
    }

    BST &operator=(BST other){
        swap(_head, other._head);
        return *this;
    }

    int &operator[](const string &key){
        Node **temp = &_head;
        while(*temp){
            if((*temp)->_data.first < key){
                temp = &(*temp)->_right;
            }
            else if((*temp)->_data.first > key){
                temp = &(*temp)->_left;
            }
            else return (*temp)->_data.second;
        }
        (*temp) = new Node({key, -1});
        return (*temp)->_data.second;
    }

    const int &operator[](const string &key) const{
        Node *temp = _head;
        while(temp){
            if((temp)->_data.first < key){
                temp = (temp)->_right;
            }
            else if((temp)->_data.first > key){
                temp = (temp)->_left;
            }
            else return (temp)->_data.second;
        }
        return -1;
    }
};

#define Map GradeDB

class Map{
private:
    BST _bst;

public:
    Map()=default;
    Map(const Map &other){
        _bst = other._bst;
    }

    ~Map()=default;

    Map &operator=(Map other){
        swap(_bst, other._bst);
        return *this;
    }

    void readGradeList(istream &is){
        string key;
        int value;
        while(is >> key >> value){
            _bst[key] = value;
        }
    }

    int findGrade(const string &key) const{
        return _bst[key];
    }
};

int main() {
    GradeDB g;
    ifstream f;
    f.open("../grade_tree", std::ios::in);
    g.readGradeList(f);
    f.close();
    int grade = g.findGrade("swanson");
    if (grade > 0) {
        std::cout << "Ron's C++ grade: " << grade << std::endl;
    } else {
        std::cout << "Grade not found" << std::endl;
    }
}