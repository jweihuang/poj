#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class Node{
public:
	int coef,power;
	Node *_next;
	Node(){ _next=NULL;}; //
	Node(int n,int m, Node *_p):coef(n),power(m), _next(_p){};
};
class CList:public Node{
private:
	Node *_head, *_tail;
	Node *set_pos(const int a);
public:
	CList(){ 
		_head=_tail=new Node();
	};
	~CList(){
		Node *_temp;
		while(_head!=NULL){
			_temp=_head;
			_head=_head->_next;
			delete _temp;
		}
	}
	void insert(const int a, const int b);
	void output_list();
};
Node* CList::set_pos(const int a){
	Node *_p =_head->_next;
	Node *_q =_head;
	while(_p!=NULL){
		if(_p->power<=a)
			return _q; //_q_p玡８竊翴
		_q = _p;
		_p = _p->_next;
	}
	return _q;
}
void CList::insert(const int a, const int b){ //a:玒计,b:Ω经
	Node *_p=set_pos(b);
	if(_p->_next!=NULL && _p->_next->power==b){ //Ω经,钡
		_p->_next->coef+=a;
	}
	else{//ぃΩ经,ミ穝竊翴
		Node *_q = new Node(a,b,_p->_next);
		_p->_next=_q;
		if(_p==_tail)
			_tail=_q;
	}	
}
void CList::output_list(){
	Node *_p=_head->_next;
	while(_p!=NULL){
		if(_p->coef!=0)
			printf("[ %d %d ] ",_p->coef,_p->power);
		_p=_p->_next;
	}
	printf("\n");
}

int main() {
	//freopen("in.txt","r",stdin); 
    //freopen("out.txt","w",stdout);
	int h,n,m;
	scanf("%d",&h);
	while(h--){
		CList f_x;
		scanf("%d %d",&n, &m);
		while(m>=0){
			f_x.insert(n,m);
			scanf("%d %d",&n, &m);
		}
		scanf("%d %d",&n, &m);
		while(m>=0){
			f_x.insert(n,m);
			scanf("%d %d",&n, &m);
		}
		f_x.output_list();
	}
	//fclose(stdin); 
    //fclose(stdout);
	//system("PAUSE");
    return 0;
}
