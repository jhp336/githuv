#include <iostream>
using namespace std;

int main() {
    int n=0;
    cin>>n;
    int t[n]={ };
    for(int i=0;i<n;i++)
    cin>>t[i];
    for (int i=0;i<n;i++)
    for (int j=0;j<n-i;j++)
    if (t[i]>t[i+j]){
    int temp;
    temp=t[i];
    t[i]=t[i+j];
    t[i+j]=temp;
    }

    int count[n]={0};
    for(int i=0;i<n;i++)
    count[i+1]=t[i]+count[i];
    int ans=0;
    for (int i=1;i<n+1;i++)
    ans=count[i]+ans;
    cout<<ans<<endl;

    return 0;

}
