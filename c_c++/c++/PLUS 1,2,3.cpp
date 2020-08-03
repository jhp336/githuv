#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int a[10]{0};
        a[0]=1;
        a[1]=2;
        a[2]=4;
        for(int i=3;i<n;i++)
        a[i]=a[i-3]+a[i-2]+a[i-1];

        cout<<a[n-1]<<'\n';
    }
}