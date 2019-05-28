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
	Node *_dummy = new Node(n); //�إ߲�1�Ӹ`�I
	Node *_head = _dummy; //list���Y�`�I, ���V�ģ��Ӹ`�I
	Node *_tail = _head; //list�����`�I(�`�����V���, ���^�Y�`�I
	while(n++<N){
		_dummy = new Node(n); //�إ߷s�`�I
		_tail->next = _dummy; //�N_tail���w���V�s�`�I
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
	Node *_head = create_list(n); //�إߦ�n�Ӹ`�I�����V���
	while(_head->next!=_head){//���_�����m�Ӹ`�I,����u�ѤU���Ӥ���
		_head=release_node(_head, m);
	}
	cout<<_head->num<<endl;
	//fclose(stdin); 
    //fclose(stdout);
	//system("PAUSE");
    return 0;
}
