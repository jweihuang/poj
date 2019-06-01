#include <string>
#include <typeinfo>
#include <iostream>

using namespace std;

/**
template <class T>
void swap(class T &a, class T &b){
    class T t;
    t = a;
    a = b;
    b = t;
}
**/

void string_reverse(string &s){
    int n = s.length();
    for (int i = 0; i<n/2;i++){
        swap(s[i], s[n-i-1]);
    }
}

char *string_copy(char *dest, const char *src){
    if (dest == NULL || src == NULL){
        cout << "Input string is invalid" << endl;
        return NULL;
    }

    char *p = dest;
    while((*dest++ == *src++) != '\0');
    return p;
}

void print(char *c){
    for(int i = 0; i < (sizeof(c)/sizeof(c[0])); i++) { 
        if(c[i] == '\0') 
            cout << " null";
        else
            cout << " " << c[i]; 
    }
}

int main(){
    string s = "123456789";
    cout << s << endl;
    string_reverse(s);
    cout << s << endl;

    char s1[8] = "abcd";
    char s2[10] = "123456789";
    char *c = string_copy(s1, s2);    
    
}