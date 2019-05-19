#include <iostream>
#include <stdio.h>
using namespace std;
/*
描述:一張普通的國際象棋棋盤，它被分成8x8 的64 個方格。
     設有形狀一樣的多米諾牌，每張牌恰好覆蓋棋盤上相鄰的兩個方格，即一張多米諾牌是一張1x2 或 2x1的牌
	 那麼，是否能夠把 32 張多米諾牌擺放到棋盤上，使得任何兩張多米諾牌均不重疊，每張多米諾牌覆蓋兩個方格，並且棋盤上所有的方格都被覆蓋住?
	 我們把這樣一種排列稱為棋盤被多米諾牌完美覆蓋。
	 請透過編程對 3xN 棋盤的不同的完美覆蓋的總數進行計算。

輸入:一次輸入可能包含多行，每一行分別給出不同的 N 值(即3xN 棋盤的列數)。當輸入-1時結束。N 的值最大不超過30
輸出:針對每一行的 N 值，輸出 3xN 棋盤的不同的完美覆蓋的總數。

*/
int a_m(int m);
int b_m(int m);

int a_m(int m){
	if(m==0) 
		return 1;
	if(m==1)
		return 0;
	return 2*b_m(m-1)+a_m(m-2);
}
int b_m(int m){
	if(m==0)
		return 0;
	if(m==1)
		return 1;
	return a_m(m-1)+b_m(m-2);
}


int main() {
	//freopen("in.txt","r",stdin); 
    //freopen("out.txt","w",stdout); 
	int n;
    cin>>n;//scanf("%d", &n);
	while(n!=-1){
		int k;
		if(n==0)
			k=1;
		else if (n%2 ==0)
			k=a_m(n)+b_m(n);
		else
			k=0;
		cout<<k;
		cin>>n;
		if(n!=-1)
			cout<<endl;
	}	
	//fclose(stdin); 
    //fclose(stdout);
	//system("PAUSE");
    return 0;
}
