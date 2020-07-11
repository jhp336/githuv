#include <iostream>
using namespace std;
int main() {
    int pay,ch,cnt=0;;
    cin>>pay;
    int c[6]={500,100,50,10,5,1};
    ch=1000-pay;
    for(int i=0;i<6;i++){
        if(c[i]<=ch)
        cnt=cnt+ch/c[i];
        ch=ch%c[i];
    }
    cout<<cnt;
    return 0;
}