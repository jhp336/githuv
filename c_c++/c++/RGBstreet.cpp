#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int price[3];
    int ans[n][3];
    for(int i=0;i<n;i++){
        cin>>price[0]>>price[1]>>price[2];
        if(i==0){
            ans[i][0]=price[0];
            ans[i][1]=price[1];
            ans[i][2]=price[2];
        }
        else {
            ans[i][0]=min(ans[i-1][1],ans[i-1][2])+price[0];
            ans[i][1]=min(ans[i-1][0],ans[i-1][2])+price[1];
            ans[i][2]=min(ans[i-1][1],ans[i-1][0])+price[2];
        }
    }
    int sum=min(ans[n-1][0],min(ans[n-1][1],ans[n-1][2]));
    cout<<sum;
    
}

    