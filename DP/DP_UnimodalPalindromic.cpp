#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_NUM 249

unsigned long pal[MAX_NUM][MAX_NUM/3]={0};

void palindromic(int num){
	pal[0][0]=0; pal[1][0]=1; pal[1][1]=1;
	for(int i=2; i<=num; i++){
		pal[i][0]=1;
		for (int j=1; j<=i/3;j++){
			pal[i][j]=pal[i-2*j][0];
			int k=j;
			while(--k){
				pal[i][j]-=pal[i-2*j][k];
				if((i-2*j)%2==0 && (i-2*j)/2==k)
					pal[i][j]--;
			}
			pal[i][0]+=pal[i][j];
		}
		if(i%2==0)
			pal[i][0]++;
	}
}

int main() {
	//freopen("in.txt","r",stdin); 
    //freopen("out.txt","w",stdout); 
	int num;
	scanf("%d",&num);
	while(num){
		palindromic(num);
		cout<<num<<' '<<pal[num][0]<<endl;//printf("%d %d\n",num, pal[num][0]);
		scanf("%d",&num);
	}
	//fclose(stdin); 
    //fclose(stdout);
	//system("PAUSE");
    return 0;
}
