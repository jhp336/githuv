#include <iostream>
#include <algorithm>
using namespace std;    
string arr[3]={"AA","V2","RE4"};
int cal(string a){
    int cnt=0;
    for(int i=0;i<a.length();i++){
        char c[1]{a[i]};
        if(atoi(c)!=0)
        cnt=cnt+atoi(c);
    }
    return cnt;
}
bool cmp(string a,string b){
    if(a.length()<b.length())
    return a<b;
    else if(a.length()>b.length())
    return a>b;
    int aa=cal(a);
    int bb=cal(b);
    if(aa<bb)
    return a<b;
    else if(aa>bb)
    return a>b;
    if(a<b)
    return a<b;
    else return a>b; 
}
int main() {
    sort(arr,arr+3,cmp);
}