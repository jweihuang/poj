#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class Node{
public:
	int num;
	Node *ahead,*next;
	Node(int n=0):num(n){}
};
Node* create_list(int N){
	int n=1;
	Node *_dummy = new Node(n); //建立第1個節點
	Node *_head = _dummy; //list的頭節點, 指向第ㄧ個節點
	Node *_tail = _head; //list的尾節點(循環雙向鏈表, 接回頭節點
	while(n++<N){
		_dummy = new Node(n); //建立新節點
		_tail->next = _dummy; //將_tail指針指向新節點
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
	//freopen("in.txt","r",stdin); 
    //freopen("out.txt","w",stdout);
	int n,m;
	scanf("%d %d",&n, &m);
	Node *_head = create_list(n); //建立有n個節點的雙向鏈表
	while(_head->next!=_head){//不斷釋放第m個節點,直到只剩下ㄧ個元素
		_head=release_node(_head, m);
	}
	cout<<_head->num<<endl;
	//fclose(stdin); 
    //fclose(stdout);
	//system("PAUSE");
    return 0;
}
