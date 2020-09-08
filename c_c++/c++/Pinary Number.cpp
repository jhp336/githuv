#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long pn[n+1];
    pn[1]=1,pn[2]=1;
    for(int i=3;i<n+1;i++){
        pn[i]=pn[i-1]+pn[i-2];
    }
    cout<<pn[n];
    return 0;
}