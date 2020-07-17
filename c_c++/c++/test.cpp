#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
    int n,m,cnt=0;
    n=3,m=4;
    int va[n][m]{{0,0,0,0},{0,0,1,0},{0,0,0,0}};
    int vb[n][m]{{1,0,0,1},{1,0,1,1},{1,0,0,1}};
    if (m<3||n<3){
        cnt=-1;
        for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (va[i][j]==vb[i][j])
            cnt=0;
        }
    for (int i=0;i<n-2;i++){
        for (int j=0;j<m-2;j++){
            if(va[i][j]!=vb[i][j]){
                for(int k=i;k<i+3;k++)
                for(int l=j;l<j+3;l++){
                    if (va[k][l]==0)
                    va[k][l]=1;
                    else va[k][l]=0;
                }
                cnt++;
                if (j==m-3)
                if (va[i][j+1]!=vb[i][j+1]||va[i][j+2]!=vb[i][j+2])
                cnt=-1;
            }
        }
    }
    cout<<cnt;
    return 0;

}