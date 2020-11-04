#include <iostream>
using namespace std;
long long cnt=0;
void div(int n,int cw,int ch){
    if(cw==ch&&cw==n&&ch==n)
    return ;
    if(cw==ch){
        div(n,cw+1,ch);
    }
     
    else if(cw>ch){
        div(n,cw+1,ch);
        div(n,cw,ch+1);
    }
}
int main() {
    while(1){
        cnt=0;
        int n;
        cin>>n;
        if(n==0)
        return 0;
        div(n,0,0);
        cout<<cnt<<'\n';
    }
}