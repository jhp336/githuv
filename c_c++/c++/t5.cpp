#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n,r,c;
    n=2,r=3,c=1;
    int ans=0;
    if(r%2==0)
    ans=pow(2,n+1)*(r/2);
    else ans=pow(2,n+1)*((r-1)/2)+2;
    if (c%2==0)
    ans=ans+2*c;
    else ans=ans+2*(c-1)+1;
    cout<<ans;
    return 0;
}