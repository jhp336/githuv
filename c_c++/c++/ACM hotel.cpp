#include <iostream>
using namespace std;
int main() {
    int t,h,w,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>h>>w>>n;
        int a=n%h;
        int b=n/h+1;
        if(a==0){
        a=h;
        b--;
        }
        cout<<100*a+b<<endl;
    }
    return 0;
}