#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int brr[100][100], L[100][100], R,C;

void bubble_sort(int (*a)[3], int n){
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < n - i; j++)	{
			if (a[j - 1][0] > a[j][0]) {
				int tmp;
				for(int k=0; k<3; k++){
					tmp = a[j][k];
					a[j][k] = a[j - 1][k];
					a[j - 1][k] = tmp;
				}
			}
		}
	}
}
int search(int (*arr)[3], int n){
	int max_path=1;
	int to[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int x0,y0, x1,y1;
	for(int i=0; i<n; i++){
		x0=arr[i][1];
		y0=arr[i][2];
		for(int j=0; j<4; j++){
			x1=x0+to[j][0];
		    y1=y0+to[j][1];
			if(x1>=0 && x1<R && y1>=0 && y1<C && brr[x0][y0]<brr[x1][y1]){
				L[x1][y1]=std::max(L[x1][y1],L[x0][y0]+1);
				if(L[x1][y1] > max_path)
					max_path=L[x1][y1];
			}
		}	
	}
	return max_path;
}

int main() {
	//freopen("in.txt","r",stdin); 
    //freopen("out.txt","w",stdout); 
	int arr[10000][3];
    scanf("%d %d",&R,&C);//cin>>R>>C;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			scanf("%d",&brr[i][j]);//cin>>brr[i][j];
			arr[i*C+j][0]=brr[i][j];
			arr[i*C+j][1]=i;
			arr[i*C+j][2]=j;
			L[i][j]=1;
		}
	}
	bubble_sort(arr,R*C);
	int max_path=search(arr,R*C);
	printf("%d",max_path);
	//fclose(stdin); 
    //fclose(stdout);
	//system("PAUSE");
    return 0;
}
