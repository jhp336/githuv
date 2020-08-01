#include<vector>
#include <iostream>
using namespace std;
vector <int> v;
int cnt=0;
void pick(int a[27][27],int i,int j){
    if(a[i][j]==0)
    return ;
    a[i][j]=0;
    v[cnt-1]++;
    pick(a,i-1,j);
    pick(a,i,j-1);
    pick(a,i+1,j);
    pick(a,i,j+1);
}
int main() {
    int n=3;
    int a[27][27]{{0,0,0,0,0},{0,1,0,0,0},{0,0,1,1,0},{0,0,1,0,0},{0,0,0,0,0}};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i+1][j+1]==1){
                v.push_back(0);
                cnt++;
                pick(a,i+1,j+1);
            }
        }
    }
    cout<<cnt<<'\n';
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<'\n';

    return 0;
}