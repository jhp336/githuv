#include <iostream>
using namespace std;
int find(int big,int small,int b, int s){
    if(b==s) return b;
    int ans=s;
    int i=0;
    for(;b!=s;i++){
        s=(s+small)%big;
        if(s==0)s=big;
        if(ans==s)
        return-1;
    }
    ans=ans+small*i;
    return ans;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int m,n,x,y,i=0;
        cin>>m>>n>>x>>y;
        int ans;
        if(m<n)
        ans=find(n,m,y,x);
        else ans=find(m,n,x,y);
        cout<<ans<<'\n';
    }
}