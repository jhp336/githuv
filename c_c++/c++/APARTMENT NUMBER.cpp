#include<vector>
#include <iostream>
#include<algorithm>
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
    int n;
    cin>>n;
    int a[27][27]{0};
    for(int i=1;i<n+1;i++){
        string s;
        cin>>s;
        for(int j=1;j<n+1;j++)
        a[i][j]=s[j-1]-48;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(a[i][j]==1){
                v.push_back(0);
                cnt++;
                pick(a,i,j);
            }
        }
    }
    sort(v.begin(),v.end());
    cout<<cnt<<'\n';
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<'\n';

    return 0;
}