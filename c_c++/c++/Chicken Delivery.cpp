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
    vector <vector <int>> tmp3(y,vector<int>(x));
    for (int j=0;j<y;j++){
        for(int i=0;i<x;i++){
            int tmp=v[i].r-v2[j].r;
            if(tmp<0)
            tmp=tmp*(-1);
            int tmp2=v[i].c-v2[j].c;
            if(tmp2<0)
            tmp2=tmp2*(-1);
            tmp3[j][i]=tmp+tmp2;
        }
    }
    for(int j=0;j<x;j++){
        int min;
        min=tmp3[0][j];
        for(int i=0;i<y;i++){
            if(min>tmp3[i][j])
            min=tmp3[i][j];
        }
        sum=sum+min;
    }
    

    cout<<sum;
    return 0;
}