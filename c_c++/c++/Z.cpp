#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n,r,c;
    cin>>n>>r>>c;
    int ans=0;
    for(int i=0;i<n;i++){
        int x=pow(2,n-i-1);
        if(r<x&&c<x)
        ans=ans;
        else if(r<x&&c>=x){
            ans=ans+pow(2,2*(n-i-1));
            c=c-x;
        }
        else if(r>=x&&c<x){
            ans=ans+pow(2,2*(n-i-1))*2;
            r=r-x;
        }
        else if(r>=x&&c>=x){
            ans=ans+pow(2,2*(n-i-1))*3;
            r=r-x;
            c=c-x;
        }
    }
    cout<<ans;
    return 0;
    
}