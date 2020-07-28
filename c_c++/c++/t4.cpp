#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        int m,n,k;
        cin>>m>>n>>k;
        vector <vector<int>> v(n,vector<int>(m,0));
        for(int j=0;j<k;j++){
            int a,b;
            cin>>a>>b;
            v[b][a]=1;
        }
        int cnt=0,ch=0;
        for(int j=0;j<n;j++){
            ch=0;
            for(int l=0;l<m;l++){
                if(j==0){
                    if(ch==0&&v[j][l]==1){
                        cnt++;
                        ch=1;
                    }
                    else if(v[j][l]==0){
                        if(l<m-1&&l>0){
                        if(v[j+1][l-1]==1&&v[j+1][l]==1&&v[j+1][l+1]==1)
                        ch=1;
                        else ch=0;
                        }
                        else if(l==0)
                    }
                }
                else {
                    if(ch==0&&v[j][l]==1&&v[j-1][l]==0){
                        cnt++;
                        ch=1;
                    }
                    else if(v[j][l]==0){
                        if(j<n-1&&l<m-1&&l>0){
                        if(v[j+1][l-1]==1&&v[j+1][l]==1&&v[j+1][l+1]==1)
                        ch=1;
                        else ch=0;
                        }
                    }
                    else ch=1;
                }
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}