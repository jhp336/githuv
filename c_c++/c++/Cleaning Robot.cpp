#include <iostream>
#include <vector>
using namespace std;
int ans=0,cnt=0;;
void move(int& a,int& b,vector <vector<int>>& v,int& d){
    while (1){
        if(d==0){
            if(cnt==4){
                if(v[a+1][b]==1)
                break;
                else {
                    a++;
                    cnt=0;
                }
            }
            else {
                d=3;
                if(v[a][b-1]==0){
                    b--;
                    ans++;
                    v[a][b]=2;
                    cnt=0;
                }
                else cnt++;
            }
        }
        else if(d==1){
            if(cnt==4){
                if(v[a][b-1]==1)
                break;
                else {
                    b--;
                    cnt=0;
                }
            }
            else {
                d=0;
                if(v[a-1][b]==0){
                    a--;
                    ans++;
                    v[a][b]=2;
                    cnt=0;
                }
                else cnt++;
            }
        }
        else if(d==2){
            if(cnt==4){
                if(v[a-1][b]==1)
                break;
                else {
                    a--;
                    cnt=0;
                }
            }
            else{
                d=1;
                if(v[a][b+1]==0){
                    b++;
                    ans++;
                    v[a][b]=2;
                    cnt=0;
                }
                else cnt++;
            }
        }
        else {
            if(cnt==4){
                if(v[a][b+1]==1)
                break;
                else {
                    b++;
                    cnt=0;
                }
            }
            else{
                d=2;
                if(v[a+1][b]==0){
                    a++;
                    ans++;
                    v[a][b]=2;
                    cnt=0;
                }
                else cnt++;
            }
        }
    }
}
int main() {
    int n,m,cnt=0;
    cin>>n>>m;
    vector <vector<int>> v (n,vector<int>(m));
    int rr,rc,d;
    cin>>rr>>rc>>d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    ans++;
    v[rr][rc]=2;
    move(rr,rc,v,d);
    cout<<ans;
    return 0;
}