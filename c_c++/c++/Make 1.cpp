#include <iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+1]{0};
    a[1]=0;
    for(int i=2;i<n+1;i++){
        a[i]=a[i-1]+1;
        if(i%2==0)
        a[i]=min(a[i],a[i/2]+1);
        if(i%3==0)
        a[i]=min(a[i],a[i/3]+1);
    }
    cout<<a[n];
    return 0;
}