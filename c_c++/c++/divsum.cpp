#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int m,l;
    int cnt;
    int minm=0;
    for(int i=0;i<=6;i++)
    if(n>pow(10,i-1))
    cnt=i;
    
    for(int i=n-1;i>n-9*(cnt+1);i--){
        m=i;
        l=m;
        int cnt2=cnt;
        for(;cnt2>0;cnt2--){
            int a=m%(int)pow(10,cnt2);
            int b=(int)pow(10,cnt2-1);
            l=l+a/b;
            
        }
        if(n==l)
        minm=m;
    }
    cout<<minm;
    return 0;
}