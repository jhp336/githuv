#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        int arr[2][n];
        for(int j=0;j<2;j++){
            for(int i=0;i<n;i++){
                cin>>arr[j][i];
            }    
        }
        for(int i=0;i<n;i++){
            if(i==1){
                arr[0][i]=arr[0][i]+arr[1][i-1];
                arr[1][i]=arr[1][i]+arr[0][i-1];
            }
            else if(i>1){
                arr[0][i]=arr[0][i]+max(arr[1][i-1],arr[1][i-2]);
                arr[1][i]=arr[1][i]+max(arr[0][i-1],arr[0][i-2]);
            }
        }   
        cout<<max(arr[0][n-1],arr[1][n-1])<<'\n';
    }

    return 0;
}