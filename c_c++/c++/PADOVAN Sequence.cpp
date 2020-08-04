#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int n;
        cin>>n;
        long long p[101]{0};
        p[1]=1;
        p[2]=1;
        p[3]=1;
        p[4]=2;
        p[5]=2;
        for(int i=6;i<n+1;i++){
            p[i]=p[i-5]+p[i-1];
        }
        cout<<p[n]<<'\n';
    }
}