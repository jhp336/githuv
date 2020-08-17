#include<iostream>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int a=0;a<t;a++){
        int n,m;
        cin>>n>>m;
        double ans=1;
        for(int i=0;i<n;i++){
            ans=ans*(m-i);
            ans=ans/(n-i);
        }
        cout.precision(10);
        cout<<ans<<'\n';
    }
    return 0;
}