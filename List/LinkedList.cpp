#include <iostream>

using namespace std;

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
        bool remove(int x);
        bool reverse();
        void clear();
        void print();
};

void LinkedList::print(){
    if (first == 0){
        cout << "The linked-list is empty" << endl;
    }
    else{
        Node *iter = first;
        while (iter != 0){
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << endl;
    }
}

void LinkedList::push_front(int x){
    Node *node = new Node(x);
    node->next = first;
    first = node;
}

void LinkedList::push_back(int x){
    Node *node = new Node(x);
    if (first == 0){
        first = node;
    }
    else{
        Node *iter = first;
        while(iter->next != 0){
            iter = iter->next;
        }
        iter->next = node;
    }
}

bool LinkedList::remove(int x){
    Node *iter = first;
    Node *prev = 0;

    while(iter != 0 && iter->data != x){
        prev = iter;
        iter = iter->next;
    }
    
    if(iter ==0) { //linked-list is empty or element not found
        return false;
    }
    else if(iter == first) { //remove first node
        first = iter->next;
        delete iter;
        iter = 0;
        return true;
    }
    else {
        prev->next = iter->next;
        delete iter;
        iter =0;
        return true;
    }
}

void LinkedList::clear(){

    while(first!=0){
        Node *temp = first;
        first = first->next;
        delete temp;
        temp = 0; 
    }
}

bool LinkedList::reverse(){
    Node *iter = first;
    Node *prev = 0;
    Node *rear = first->next;

    if (iter==0 || rear == 0){
        return false;
    }

    while(rear!=0){    
        iter->next = prev;
        prev = iter;
        iter = rear;
        rear = rear->next;
    }

    iter->next = prev;
    first = iter;

    return true;
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