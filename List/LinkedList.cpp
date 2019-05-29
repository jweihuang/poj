#include <iostream>
using std::cout;
using std::endl;

class LinkedList; // 為了將class LinkedList設成class ListNode的friend, 需要先宣告

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
    // int size; // size of linked list
    Node *first; // first node
public:
    LinkedList():first(0){};
    void print(); 
    void push_front(int x); 
    void push_back(int x);
    void remove(int x); 
    void clear(); // clear all element in the list
    void reverse(); // reverse linked list: 1->2->3 to 3->2->1
};


void LinkedList::print(){

    if (first == 0) {                      // 如果first node指向NULL, 表示list沒有資料
        cout << "List is empty.\n";
        return;
    }

    Node *current = first;             // 用pointer *current在list中移動
    while (current != 0) {                 // Traversal
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


void LinkedList::push_front(int x){

    Node *newNode = new Node(x);   // 配置新的記憶體
    newNode->next = first;                 // 先把first接在newNode後面
    first = newNode;                       // 再把first指向newNode所指向的記憶體位置
}


void LinkedList::push_back(int x){

    Node *newNode = new Node(x);   // 配置新的記憶體

    if (first == 0) {                      // 若list沒有node, 令newNode為first
        first = newNode;
        return;
    }

    Node *current = first;
    while (current->next != 0) {           // Traversal
        current = current->next;
    }
    current->next = newNode;               // 將newNode接在list的尾巴
}


void LinkedList::remove(int x){

    Node *current = first;      
    Node *previous = 0;
    while (current != 0 && current->data != x) {  // Traversal
        previous = current;                       // 如果current指向NULL
        current = current->next;                  // 或是current->data == x
    }                                             // 即結束while loop

    if (current == 0) {                 // list沒有要刪的node, 或是list為empty
        std::cout << "There is no " << x << " in list.\n";
        // return;
    }
    else if (current == first) {        // 要刪除的node剛好在list的開頭
    	first = current->next;          // 把first移到下一個node
        delete current;                 // 如果list只有一個node, 那麼first就會指向NULL
        current = 0;                    // 當指標被delete後, 將其指向NULL, 可以避免不必要bug
        // return;                     
    }
    else {                              // 其餘情況, list中有欲刪除的node, 
        previous->next = current->next; // 而且node不為first, 此時previous不為NULL
        delete current;
        current = 0;
        // return;
    }
}

void LinkedList::clear(){

    while (first != 0) {  // traversal
        Node *current = first;
        first = first->next;
        delete current;
        current = 0;
    }
}


void LinkedList::reverse(){

    if (first == 0 || first->next == 0) {
        // list is empty or list has only one node
        return;
    }

    Node *previous = 0;
    Node *current = first;
    Node *preceding = first->next;

    while (preceding != 0) {
        current->next = previous;      // 把current->next轉向
        previous = current;            // previous往後挪
        current = preceding;           // current往後挪
        preceding = preceding->next;   // preceding往後挪
    }                                  // preceding更新成NULL即跳出while loop

    current->next = previous;          // 此時current位於最後一個node, 將current->next轉向
    first = current;                   // 更新first為current
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