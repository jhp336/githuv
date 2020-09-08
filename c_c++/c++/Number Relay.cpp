#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long cnt=0;
    for(int i=1;i<n+1;i++){
        if(i<10)
        cnt++;
        else if(i<100){
            cnt=cnt+2;
        }
        else if(i<1000){
            cnt=cnt+3;
        }
        else if(i<10000){
            cnt=cnt+4;
        }
        else if(i<100000){
            cnt=cnt+5;
        }
        else if(i<1000000){
            cnt=cnt+6;
        }
        else if(i<10000000){
            cnt=cnt+7;
        }
        else if(i<100000000){
            cnt=cnt+8;
        }
        else cnt=cnt+9;
    }
    cout<<cnt;
    return 0;
}