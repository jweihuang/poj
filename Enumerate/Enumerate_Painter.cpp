#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
/*
�y�z:���@�ӥ���Ϊ��١A��N*N�ӥ���Ϊ��j�զ��A�䤤�@�ǿj�O�զ⪺�A�t�~�@�ǿj�O���⪺�C
     Bob�O�ӵe�a�A�Q��������j�������C���L���e�����n�ϡC
	 ��L�εe����e��(i, j)�Ӧ�m���j�ɡA��m(i-1, j)�B(i+1,j)�B(i,j-1)�B(i,j+1)�W���j���|�����C��C
	 �ЧA���UBob�p��X�ֻ̤ݭn��e�h�ֶ��j�A�~��ϩҦ��j���C�ⳣ�ܦ�����C
��J:�Ĥ@��O�Ӿ��t(1<=t<=20)�A��ܭn���ժ��רҼơC�M��Ot�ӮרҡC�C�ӮרҪ�����O�@�Ӿ��n (1<=n<=15)�A����٪��j�p�C
     ���U�Ӫ�n�����٪���l���A�C�C�@��]�tn�Ӧr�šC��i�檺��j�Ӧr�Ū�ܦ���m(i,j)�W���j���C��C"w"��ܥտj�A"y"��ܶ��j�C
��X:�C�Ӯרҿ�X�@��C�p�GBob����N�Ҧ����j�������A�h��X�ֻ̤ݭn��e���j�ơA�_�h��X��inf���C
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
			_press[i] = _press[(N+1)*(N+2)+(i+1)] = _press[i*(N+2)] = _press[i*(N+2)+(N+1)] = 0;//�N�~��]�w��0
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
