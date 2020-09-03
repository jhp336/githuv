#include <iostream>
using namespace std;
int main() {
    int n,x,y,cnt=0;
    cin>>n>>x>>y;
    int tmp1=x+1,tmp2=y+1;
    while(tmp1!=tmp2){
        tmp1=tmp1/2;
        tmp2=tmp2/2;
        cnt++;
        tmp1=tmp1+1;
        tmp2=tmp2+1;
    }
    cout<<cnt;
    return 0;
}