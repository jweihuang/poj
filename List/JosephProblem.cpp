#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class Node {
public:
	int num;
	Node *ahead,*next;
	Node(int n=0):num(n){}
};

Node* create_list(int N){
	int n=1;
	Node *_dummy = new Node(n); //
	Node *_head = _dummy; //list
	Node *_tail = _head; //list
	while(n++<N){
		_dummy = new Node(n); 
		_tail->next = _dummy; 
		_dummy->ahead = _tail;
		_tail = _tail->next;
	}
	_tail->next=_head;
	_head->ahead=_tail;
	return _head;
}

Node* release_node(Node *_p, int m){
	int k=1;
	Node *_temp=_p;
	while(k<m){
		_temp = _temp->next;
		k++;
	}
	_temp->ahead->next=_temp->next;
	_temp->next->ahead=_temp->ahead;
	_p=_temp->next;
	delete _temp;
	return _p;
}

int main() {
	freopen("in.txt","r",stdin); 
    freopen("out.txt","w",stdout);

	int n,m;
	scanf("%d %d",&n, &m);
	Node *_head = create_list(n); 
	
	while(_head->next!=_head){ 
		_head=release_node(_head, m);
	}
	cout<<_head->num<<endl;
	
	fclose(stdin); 
    fclose(stdout);
	///system("PAUSE");
    return 0;
}
