#include <iostream>
using namespace std;
int main() {
    int t,h,w,n;
    t=1;
    h=6;
    n=1;
    
    for(int i=0;i<t;i++){
        
        int a=n%h;
        int b=n/h+1;
        
        cout<<100*a+b<<endl;
    }
    return 0;
}