#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    char arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cin>>arr[i][j];
    }
    int ans,leng;
    if(n>m)
    leng=m;
    else leng=n;
    while (leng>0){
        for(int i=0;i<n-leng+1;i++){
            for(int j=0;j<m-leng+1;j++){
                char val=arr[i][j];
                if(arr[i+leng-1][j]==val&&arr[i][j+leng-1]==val&&arr[i+leng-1][j+leng-1]==val){
                    ans=leng*leng;
                    cout<<ans;
                    return 0;
                }
            }
        }
        leng--;
    }    

}