#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio;
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        int n;
        int cnt0[41];
        int cnt1[41];
        cin>>n;
        for(int j=0;j<n+1;j++){
            if(j==0){
                cnt0[j]=1;
                cnt1[j]=0;
            }
            else if(j==1){
                cnt0[j]=0;
                cnt1[j]=1;
            }
            else {
                cnt0[j]=cnt0[j-1]+cnt0[j-2];
                cnt1[j]=cnt1[j-1]+cnt1[j-2];
            }
        }
        cout<<cnt0[n]<<' '<<cnt1[n]<<'\n';
    }
    return 0;
}