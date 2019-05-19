#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, r, board[8][8], valid[8];

void DFS(int x, int y, int k){
	if(board[x][y] || valid[y]==1) //位置已經使用過或為空白區域
		return;
	if(k==0){
		r++;
		return;
	}
	else{
		valid[y]=1;
		for(int i=x+1; i<n; i++){
			for (int j=0; j<n; j++){				
				DFS(i, j, k-1);				
			}
		}
		valid[y]=0;
		return;
	}
}

int main() {
	//freopen("in.txt","r",stdin); 
    //freopen("out.txt","w",stdout); 
	int k;
	scanf("%d %d",&n, &k);
	while(n!=-1 && k!=-1){
		r=0;
		char c;
		for(int i=0; i<n; i++){
			valid[i]=0;
			for(int j=0; j<n; j++){
				cin>>c;
			    if(c=='#')
					board[i][j]=0;
				else
					board[i][j]=1;
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				DFS(i,j,k-1);
				board[i][j]=1;
			}
		}
		printf("%d\n",r);
		scanf("%d %d",&n, &k);
	}
	//fclose(stdin); 
    //fclose(stdout);
	//system("PAUSE");
    return 0;
}
