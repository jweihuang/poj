#include <iostream>
#include <stdio.h>
using namespace std;
/*
描述:
給出2個正整數集合A = {pi | 1 <= i <= a}，B = {qj | 1 <= j <= b}和一個正整數s。問題是：使得pi + qj = s 的不同的(i,j)對有多少個

輸入:
第1行是測試數據的組數n，後面跟著n組測試數據。
每組測試數據占5行，
第1行是和s (1<=s<=10000)，
第2行是一個正整數a(1<=a<=10000)，表示A中元素的數目。
第3行是a個正整數，每個正整數不超過10000，表示A中的元素。
第4行是一個正整數b (1<=b<=10000)，表示B中元素的數目。
第5行是b個正整數，每個正整數不超過10000，表示B中的元素。

注意：這裏的集合和數學書上定義的集合有一點點區別→集合內可能包含相等的正整數。

輸出:
n行，每行輸出對應一個輸入。輸出應是一個非負整數。
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
