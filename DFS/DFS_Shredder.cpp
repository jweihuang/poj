#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int trial[8],sol[8];
char str[8];
int tar, update, record, count, clen;

int str2num(int p, int q){
	char tmp[8];
	int i;
	for(i=0; i<q-p; i++)
		tmp[i]=str[i+p];
	tmp[i]='\0';
	return atoi(tmp);
}
void DFS(int p, int q, int k){
	if(update > tar)
		return;	
	if(q==clen){
		if(update>record && update <=tar){ //不是相同答案
			record=update;
			count=1;
			memset(&sol, -1, sizeof(sol));
			for(int i=0; i<k; i++)
				sol[i]=trial[i];
		}
		else if(update==record && update <=tar){ //相同答案
			count++;
		}
		return;
	}
	int i=1;
	while(q+i<=clen){
		int r_val = str2num(q, q+i);
		if(update+r_val>tar)
			break;
		update+=r_val;
		trial[k]=r_val;
	    DFS(q,q+i, k+1);
	    update-=r_val;
		i++;
	}
	return;
}
int main() {
	//freopen("in.txt","r",stdin); 
    //freopen("out.txt","w",stdout);
	int num;
	scanf("%d %d",&tar, &num);
	while(num!=0 && tar!=0){
		sprintf(str,"%d",num);
		clen=strlen(str);
		count=0;
		record=0;
		update=0;
		if (num!=tar) {
			int i=1;
			while(i<= clen){
				int l_val = str2num(0, i);
				if(l_val>tar)
					break;
				trial[0]=l_val;
				update+=l_val;
				DFS(0,i,1); //切割第0位到第i位, 目前切割數的總和, 切割的順序
				update-=l_val;
				i++;
			}
			if(count==0)
				printf("error\n");
			else if(count ==1){
				printf("%d", record);
				int j=0;
				while(sol[j]!=-1){
					printf(" %d", sol[j]);
					j++;
				}
				printf("\n");
			}
			else
				printf("rejected\n");
		}
		else{
			printf("%d %d\n", num, tar); //role1: tar==num, paper is not cut
		}
		scanf("%d %d",&tar, &num);
	}
	//fclose(stdin); 
    //fclose(stdout);
	//system("PAUSE");
    return 0;
}
