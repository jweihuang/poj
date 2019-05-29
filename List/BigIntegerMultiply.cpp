#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_DIGI = 400;
class CInt {
private:
	char num[MAX_DIGI];
public:
    CInt() {}
    CInt(char a[]) { strcpy(num,a);}
    CInt(const CInt &b){ strcpy(num,b.num);}
    CInt multiply(CInt b);
    void Print(){ printf("%s\n",num);}
};

CInt CInt::multiply(CInt b) {//C=A*B
        int p,q,r;
        int u[MAX_DIGI/4],v[MAX_DIGI/4],w[MAX_DIGI/2]={0};
        char s[4]={'0' ,'0', '0','\0' };
        CInt ans;
        p = strlen(num);
        q = strlen(b.num);
        reverse(num,num+p);
        reverse(b.num,b.num+q);
        //A
        int i=0,m=0;
        r=p%3;
        for (i=0; i<p-r;i+=3){
                s[0]=num[i+2]; s[1]=num[i+1]; s[2]=num[i];
                u[m]=atoi(s);
                m++;
        }
        if(r==1){
                s[0]=num[p-r]; s[1]= '\0';
                u[m]=atoi(s);
        }
         else if (r==2){
                s[0]=num[p-r+1]; s[1]=num[p-r]; s[2]= '\0';
                u[m]=atoi(s);
        }
        else{ m--;}
        //B
        int n=0;
        r=q%3;
        i=0;
         for (i=0; i<q-r;i+=3){
                s[0]=b.num[i+2]; s[1]=b.num[i+1]; s[2]=b.num[i];
                v[n]=atoi(s);
                n++;
        }
         if(r==1){
                s[0]=b.num[q-r]; s[1]= '\0';
                v[n]=atoi(s);
        }
         else if (r==2){
                s[0]=b.num[q-r+1]; s[1]=b.num[q-r];    
                s[2]= '\0';
                v[n]=atoi(s);
        }
         else{ n--;}
         //C=A*B
         int x=0, y=0, z=0;
         int j=0;
         for(i=0;i<=m;i++){
                 for(j=0;j<=n;j++){
                        r=u[i]*v[j];
                        x=r/1000;
                        y=r%1000;
                        z=w[i+j]+y;
                        w[i+j]=z%1000;
                        w[i+j+1]=w[i+j+1]+x+(z/1000);
                }
        }
         for(i=0;i<=m+n+1;i++){
                x=w[i]%10;
                y=(w[i]/10)%10;
                z=w[i]/100;
                ans.num[i*3]=( char)(x+48);
                ans.num[i*3+1]=( char)(y+48);
                ans.num[i*3+2]=( char)(z+48);
        }
        ans.num[i*3]= '\0';
        r=i*3-1;
         while(ans.num[r]=='0' ) {
                ans.num[r]= '\0';
                r--;
        }
        reverse(ans.num,ans.num+strlen(ans.num));
        return ans;
}

int main() {    
    //freopen("in.txt","r",stdin); 
    //freopen("out.txt","w",stdout);
    char m[256],n[256];
    scanf("%s %s",&m, &n);
    CInt a(m),b(n),c;
    c = a.multiply(b);
    c.Print();
    //fclose(stdin); 
    //fclose(stdout);
    //system("PAUSE");

    return 0;
}
