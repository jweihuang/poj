#include <iostream>
#include <stdio.h>
using namespace std;
/*
�y�z:
���X2�ӥ���ƶ��XA = {pi | 1 <= i <= a}�AB = {qj | 1 <= j <= b}�M�@�ӥ����s�C���D�O�G�ϱopi + qj = s �����P��(i,j)�靈�h�֭�

��J:
��1��O���ռƾڪ��ռ�n�A�᭱���n�մ��ռƾڡC
�C�մ��ռƾڥe5��A
��1��O�Ms (1<=s<=10000)�A
��2��O�@�ӥ����a(1<=a<=10000)�A���A���������ƥءC
��3��Oa�ӥ���ơA�C�ӥ���Ƥ��W�L10000�A���A���������C
��4��O�@�ӥ����b (1<=b<=10000)�A���B���������ƥءC
��5��Ob�ӥ���ơA�C�ӥ���Ƥ��W�L10000�A���B���������C

�`�N�G�o�ت����X�M�ƾǮѤW�w�q�����X���@�I�I�ϧO�����X���i��]�t�۵�������ơC

��X:
n��A�C���X�����@�ӿ�J�C��X���O�@�ӫD�t��ơC
*/


int main() {
	//freopen("in.txt","r",stdin); 
    //freopen("out.txt","w",stdout); 
	int n,a,b,s, counter;
	int arr[10000], brr;
    cin>>n;//scanf("%d", &n);
	while(n){
		counter=0;
		cin>>s>>a;
		for(int i=0; i<a; i++)
			cin>>arr[i];
		cin>>b;
		for(int i=0; i<b; i++){
			cin>>brr;
			for(int j=0; j<a; j++){
				if(brr+arr[j]==s)
					counter++;
			}
		}
		cout<<counter<<endl;
		n--;
	}	
	//fclose(stdin); 
    //fclose(stdout);
	//system("PAUSE");
    return 0;
}
