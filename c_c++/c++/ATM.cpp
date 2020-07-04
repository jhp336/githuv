#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n=0;
    cin>>n;
    int t[n]={ };
    for(int i=0;i<n;i++)
    cin>>t[i];
    sort(t,t+n);
    int count[n]={0};
    for(int i=0;i<n;i++)
    count[i+1]=t[i]+count[i];
    int ans=0;
    for (int i=1;i<n+1;i++)
    ans=count[i]+ans;
    cout<<ans<<endl;

    return 0;

}
