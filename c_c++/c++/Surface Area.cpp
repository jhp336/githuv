#include <iostream>
#include<cstring>
using namespace std;
int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    long long ans=2*n*m;
    int arr[n+2][m+2];
    memset(arr,0,sizeof(arr));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(arr[i][j]>arr[i+1][j])
            ans=ans+arr[i][j]-arr[i+1][j];
            if(arr[i][j]>arr[i-1][j])
            ans=ans+arr[i][j]-arr[i-1][j];
            if(arr[i][j]>arr[i][j-1])
            ans=ans+arr[i][j]-arr[i][j-1];
            if(arr[i][j]>arr[i][j+1])
            ans=ans+arr[i][j]-arr[i][j+1];
        }
    }
    cout<<ans;
    return 0;
}