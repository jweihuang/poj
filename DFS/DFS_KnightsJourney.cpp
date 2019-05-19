#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int p,q,board[28][28], path[28*28][2];
int to[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};  
bool route;
void DFS(int x, int y, int k){
	path[k][0]=x;
	path[k][1]=y;
	if(k==p*q-1){ //整個棋盤都走過了
		route = false;
		return;
	}
	else{ //尋找下ㄧ步
		int x1,y1;
		int i=0;
		while(i<8 && route){
			x1=x+to[i][0];
		    y1=y+to[i][1];
			if(x1>=0 && y1>=0 && x1<p && y1<q && board[x1][y1]==0){
				board[x1][y1]=1;
				DFS(x1,y1,k+1);
				board[x1][y1]=0;
			}
			i++;
		}
		return;
	}
}

int main() {
	//freopen("in.txt","r",stdin); 
    //freopen("out.txt","w",stdout); 
	int num;
	scanf("%d",&num);
	int k=1;
	while(k<=num){
		memset(board,0,sizeof(board));
		memset(path,0,sizeof(path));
		route=true;
		scanf("%d %d",&p, &q);
		board[0][0]=1;
		DFS(0,0,0);
		printf("Scenario #%d:\n",k);
		if(route)
			printf("impossible\n");
		else{
			for(int i=0; i<p*q; i++){
				printf("%c%d",path[i][1]+65,path[i][0]+1);
			}
			printf("\n");
		}
		printf("\n");
		k++;
	}
	//fclose(stdin); 
    //fclose(stdout);
	//system("PAUSE");
    return 0;
}
