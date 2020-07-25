#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct mmr{
    int r,c;
};
int main() {
    int n,m,x=0,y=0,sum=0;
    cin>>n>>m;
    int c[n][n];
    vector <mmr> v(n*n);
    vector <mmr> v2(n*n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>c[i][j];
            if(c[i][j]==1){
                v[x].r=i;
                v[x].c=j;
                x++;
            }
            else if(c[i][j]==2){
                v2[y].r=i;
                v2[y].c=j;
                y++;
            }
        }
    }
    vector <int> dis(y);
    for (int j=0;j<y;j++){
        dis[j]=0;   
        for(int i=0;i<x;i++){
            int tmp=v[i].r-v2[j].r;
            if(tmp<0)
            tmp=tmp*(-1);
            int tmp2=v[i].c-v2[j].c;
            if(tmp2<0)
            tmp2=tmp2*(-1);
            vector <vector <int>> tmp3;
            tmp3[j][i]=tmp+tmp2;
            dis[j]=dis[j]+tmp3[j][i];
        }
        sum=sum+dis[j];
    }
    sort(dis.begin(),dis.end());
    sum=0;
    for (int i=0;i<m;i++)
    sum=sum+dis[i];

    cout<<sum;
    return 0;
}