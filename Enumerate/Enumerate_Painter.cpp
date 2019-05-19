#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
/*
描述:有一個正方形的墻，由N*N個正方形的磚組成，其中一些磚是白色的，另外一些磚是黃色的。
     Bob是個畫家，想把全部的磚都塗成黃色。但他的畫筆不好使。
	 當他用畫筆塗畫第(i, j)個位置的磚時，位置(i-1, j)、(i+1,j)、(i,j-1)、(i,j+1)上的磚都會改變顏色。
	 請你幫助Bob計算出最少需要塗畫多少塊磚，才能使所有磚的顏色都變成黃色。
輸入:第一行是個整數t(1<=t<=20)，表示要測試的案例數。然後是t個案例。每個案例的首行是一個整數n (1<=n<=15)，表示墻的大小。
     接下來的n行表示墻的初始狀態。每一行包含n個字符。第i行的第j個字符表示位於位置(i,j)上的磚的顏色。"w"表示白磚，"y"表示黃磚。
輸出:每個案例輸出一行。如果Bob能夠將所有的磚都塗成黃色，則輸出最少需要塗畫的磚數，否則輸出“inf”。
*/


int guess(int *puzzle, int *press, int N){ 
    int c, r, k=0;
	for(c=1; c<N+1; c++){
		if(press[(N+2)+c]==1)
			k++;
	}
    for(r=1; r<N; r++){
        for(c=1; c<N+1; c++){
            press[(r+1)*(N+2)+c] = (puzzle[r*(N+2)+c]+press[r*(N+2)+c]+ press[(r-1)*(N+2)+c]+ press[r*(N+2)+(c-1)]+press[r*(N+2)+(c+1)]) %2;
			if(press[(r+1)*(N+2)+c]==1)
				k++;
        } 
    }
    for(c=1; c<N+1; c++) {
        if ((press[N*(N+2)+(c-1)] + press[N*(N+2)+c] + press[N*(N+2)+c+1] + press[(N-1)*(N+2)+c]) %2 != puzzle[N*(N+2)+c] )
            return -1;
    }
    return k;
}

int enumerate(int *puzzle, int *press, int N){ 
    int MAX_TRIAL=pow(2.0,N);
	int tmp=0, ans=-1;
    for (int i=1; i<N+1; i++){ 
        press[(N+2)+i] = 0; 
    }
    while(MAX_TRIAL--){
		tmp=guess(puzzle, press, N);
		if(tmp!=-1 && ans==-1)
			ans = tmp;
		else if (tmp!=-1 && tmp<ans){
			ans = tmp;
		}
		else {}
		
        press[(N+2)+1]++;
        int c = 1;
        while (press[(N+2)+c] > 1) {
            press[(N+2)+c] = 0;
            c++;
            press[(N+2)+c]++;
        }
    }
    return ans;
}

int main() {
	//freopen("in.txt","r",stdin); 
    //freopen("out.txt","w",stdout); 
    int M, N;
	char tmp[16];
    scanf("%d", &M);
	for(int i=0; i<M; i++){
		scanf("%d", &N);
		int *_press = new int[(N+2)*(N+2)];
		int *_puzzle = new int[(N+2)*(N+2)];
		for (int i=0; i<N+2; i++ )
			_press[i] = _press[(N+1)*(N+2)+(i+1)] = _press[i*(N+2)] = _press[i*(N+2)+(N+1)] = 0;//將外圍設定為0
		for(int i=1; i<N+1; i++){
			scanf("%s", &tmp);
			for(int j=0; j<N; j++){
				if (tmp[j]=='w')
					_puzzle[i*(N+2)+j+1]=1;
				else
					_puzzle[i*(N+2)+j+1]=0;
			}
		}
        int k = enumerate(_puzzle,_press, N);
		if (k==-1)
			printf("inf\n");
		else
			printf("%d\n",k);
    }
	//fclose(stdin); 
    //fclose(stdout);
	//system("PAUSE");
    return 0;
}
