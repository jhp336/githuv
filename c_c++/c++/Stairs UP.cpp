#include <iostream>
using namespace std;
int main(){
    int n,cnt=0;
    cin>>n;
    int sum[301]{0};
    int s[301]{0};
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sum[0]=s[0];
    sum[1]=s[0]+s[1];
    sum[2]=max(s[0]+s[2],s[1]+s[2]);
    for(int i=3;i<n;i++){
        sum[i]=max(sum[i-2]+s[i],sum[i-3]+s[i]+s[i-1]);
    }
    cout<<sum[n-1];
}