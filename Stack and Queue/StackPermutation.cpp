#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

template <class T>
class ArryStack{
private:
	int size, top;
public:
	ArryStack(int n):size(n),top(-1){}
	~ArryStack(){}
	void clear() {top = -1;}
	bool push(){
		if(top==size-1)
			return false;
		else{
			top++;
			return true;
		}
	}
	bool pop(){
		if(top==-1)
			return false;
		else{
			top--;
			return true;
		}
	}
};

int count=0;
void Run(ArryStack<int> a, int n){
	if(n>0 && a.push()){
		Run(a,n-1);
		a.pop();
	}
	if(a.pop()){
		Run(a,n);
	}
	else if(n==0)
		count++;
}
int main() {
	//freopen("in.txt","r",stdin); 
    //freopen("out.txt","w",stdout);
	int n;
    scanf("%d",&n);
	ArryStack<int> a(n);
	Run(a,n);
	printf("%d",count);
	//fclose(stdin); 
    //fclose(stdout);
	//system("PAUSE");
    return 0;
}
