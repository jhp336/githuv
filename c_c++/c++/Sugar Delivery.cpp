#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int bag=0;
    if(n%5==0)
    bag=n/5;
    else if(n%5==1){
        if(n==1)
        bag=-1;
        else bag=1+n/5;
    }
    else if(n%5==2){
        if (n==2||n==7)
        bag=-1;
        else bag=2+n/5;
    }
    else if(n%5==3){
        bag=1+n/5;
    }
    else if(n%5==4){
        if (n==4)
        bag=-1;
        else bag=2+n/5;
    }
    cout<<bag;
    return 0;
}