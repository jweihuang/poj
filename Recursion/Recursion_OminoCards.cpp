#include <iostream>
#include <stdio.h>
using namespace std;
/*
�y�z:�@�i���q����ڶH�ѴѽL�A���Q����8x8 ��64 �Ӥ��C
     �]���Ϊ��@�˪��h�̿յP�A�C�i�P��n�л\�ѽL�W�۾F����Ӥ��A�Y�@�i�h�̿յP�O�@�i1x2 �� 2x1���P
	 ����A�O�_����� 32 �i�h�̿յP�\���ѽL�W�A�ϱo�����i�h�̿յP�������|�A�C�i�h�̿յP�л\��Ӥ��A�åB�ѽL�W�Ҧ�����泣�Q�л\��?
	 �ڭ̧�o�ˤ@�رƦC�٬��ѽL�Q�h�̿յP�����л\�C
	 �гz�L�s�{�� 3xN �ѽL�����P�������л\���`�ƶi��p��C

��J:�@����J�i��]�t�h��A�C�@����O���X���P�� N ��(�Y3xN �ѽL���C��)�C���J-1�ɵ����CN ���ȳ̤j���W�L30
��X:�w��C�@�檺 N �ȡA��X 3xN �ѽL�����P�������л\���`�ơC

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
