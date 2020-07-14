#include<iostream>
using namespace std;
int main() {
    int n,m,k;
    int team=0;
    cin>>n>>m>>k;
    int rest;
    if(n-2*m>=0){
        rest=n-2*m;
        if(rest>=k)
        team=m;
        else team=m-((k-rest-1)/3+1);
    }
    else {
        rest=m-n/2+n%2;
        if(rest>=k)
        team=n/2;
        else team=n/2-((k-rest-1)/3+1);
    }
    cout<<team;
    return 0;
}
