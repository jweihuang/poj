#include <iostream>

class LinkedList; 

class Node{
private:
    int data;
    Node *next;
public:
    Node():data(0),next(0){};
    Node(int a):data(a),next(0){};

    friend class LinkedList;
};

class LinkedList{
    private:
        Node *first;
    public:
        LinkedList():first(0){};
        ~LinkedList(){};
        void push_front(int x);
        void push_back(int x);
        void remove(int x);
        void clear();
        void reverse();
        void print();
}

void LinkedList::push_front(int x){
    Node *node = new Node(x);
    node->next = first;
    first = node;
}

void LinkedList::print(){
    
}

int main() {

    LinkedList list;     
    list.print();    // empty list
    list.remove(4);      // empty list
    list.push_back(5);   // list: 5
    list.push_back(3);   // list: 5 3
    list.push_front(9);  // list: 9 5 3
    list.print();    //print: 9 5 3
    list.push_back(4);   // list: 9 5 3 4
    list.remove(9);      // list: 5 3 4
    list.print();    // print: 5 3 4
    list.push_front(8);  // list: 8 5 3 4
    list.print();    // print:  8 5 3 4
    list.reverse();      // list: 4 3 5 8
    list.print();    // print: 4 3 5 8
    list.clear();        // clear list
    list.print();    //print: List is empty.

    return 0;
}