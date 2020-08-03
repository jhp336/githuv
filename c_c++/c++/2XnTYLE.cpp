#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long a[1001];
    a[1]=1;
    a[2]=2;
    for(int i=3;i<n+1;i++)
    a[i]=(a[i-2]+a[i-1])%10007;

    cout<<a[n];
    return 0;
}