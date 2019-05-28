#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	//freopen("in.txt","r",stdin); 
    //freopen("out.txt","w",stdout);
	int n;
	string s;
    scanf("%d",&n);
	cin.get();
	while(n--){
		getline(cin,s);
		int i=0;
		int k=s.length();
		while(i<s.length()){
			if(s.at(i)>='a' && s.at(i)<='y' || s.at(i)>='A' && s.at(i)<='Y')
				s.at(i)++;
			else if(s.at(i)=='z'|| s.at(i)=='Z')
				s.at(i)-=25;
			i++;
		}
		printf("%s\n",s.c_str());
	}
	//fclose(stdin); 
    //fclose(stdout);
	//system("PAUSE");
    return 0;
}
