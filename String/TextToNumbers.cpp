#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std; 

int main() {
	
	typedef map<string, int> Strmap;
	Strmap str_num;
	str_num.insert(Strmap::value_type("zero",0));
	str_num.insert(Strmap::value_type("one",1));
	str_num.insert(Strmap::value_type("two",2));
	str_num.insert(Strmap::value_type("three",3));
	str_num.insert(Strmap::value_type("four",4));
	str_num.insert(Strmap::value_type("five",5));
	str_num.insert(Strmap::value_type("six",6));
	str_num.insert(Strmap::value_type("seven",7));
	str_num.insert(Strmap::value_type("eight",8));
	str_num.insert(Strmap::value_type("nine",9));
	str_num.insert(Strmap::value_type("ten",10));
	str_num.insert(Strmap::value_type("eleven",11));
	str_num.insert(Strmap::value_type("twelve",12));
	str_num.insert(Strmap::value_type("thirteen",13));
	str_num.insert(Strmap::value_type("fourteen",14));
	str_num.insert(Strmap::value_type("fifteen",15));
	str_num.insert(Strmap::value_type("sixteen",16));
	str_num.insert(Strmap::value_type("seventeen",17));
	str_num.insert(Strmap::value_type("eighteen",18));
	str_num.insert(Strmap::value_type("nineteen",19));
	str_num.insert(Strmap::value_type("twenty",20));
	str_num.insert(Strmap::value_type("thirty",30));
	str_num.insert(Strmap::value_type("forty",40));
	str_num.insert(Strmap::value_type("fifty",50));
	str_num.insert(Strmap::value_type("sixty",60));
	str_num.insert(Strmap::value_type("seventy",70));
	str_num.insert(Strmap::value_type("eighty",80));
	str_num.insert(Strmap::value_type("ninety",90));
	
	//freopen("in.txt","r",stdin); 
    //freopen("out.txt","w",stdout);
	string a;
	while(getline(cin,a)) {    
		a+=' ';
		int i=0, num[3]={0}, ans=0, res=1;
		string tmp;
		int alen=a.length();
		while(i<alen){
			if(a.at(i)!=32)
				tmp+=a.at(i);
			else if(tmp=="hundred"){
				num[0]*=100;
			    tmp="";
			}
			else if(tmp=="thousand"){
				num[1]=num[0];
			    num[0]=0; tmp="";
			}
			else if(tmp=="million"){
				num[2]=num[0];
				num[0]=0; tmp="";
			}
			else if(tmp=="negative"){
				res=-1;
				tmp="";
			}
			else{
				num[0]+=str_num[tmp];
				tmp="";
			}
			i++;
		}
		ans=num[0]+num[1]*1000+num[2]*1000000;
		ans*=res;
		if(a!=" ")
			printf("%d\n",ans);
	}
	//fclose(stdin); 
    //fclose(stdout);
	//system("PAUSE");
    return 0;
}
