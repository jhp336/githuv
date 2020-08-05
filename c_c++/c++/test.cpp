#include <iostream>
#include <vector>
using namespace std;
int cnt0=0,cnt1=0,cnt2=0;
void cut(vector<vector<int>>arr,int x,int y,int n){
    int chk=arr[y][x];
    int ch=1;
    while(n>0){
        for(int i=y;i<y+n;i++){
            for(int j=x;j<x+n;j++){
                if(arr[i][j]!=chk){
                    ch=0;
                    break;
                }
            }
            if(ch==0)
            break;
        }
        if(ch==1){
            if(chk==-1)
            cnt0++;
            else if(chk==0)
            cnt1++;
            else cnt2++;
            break;
        }
        n=n/3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cut(arr,x+n*j,y+n*i,n);
            }
        }
        break;
    }
}
int main() {
    int n;
    n=9;
    int m=2187;
    vector<vector<int>> arr{{0,0,0,1,1,1,-1,-1,-1},{0,0,0,1,1,1,-1,-1,-1},{0,0,0,1,1,1,-1,-1,-1},{1,1,1,0,0,0,0,0,0},{1,1,1,0,0,0,0,0,0},{1,1,1,0,0,0,0,0,0},{0,1,-1,0,1,-1,0,1,-1},{0,-1,1,0,1,-1,0,1,-1},{0,1,-1,1,0,-1,0,1,-1}};
    
    cut(arr,0,0,n);
    cout<<cnt0<<'\n'<<cnt1<<'\n'<<cnt2;
    return 0;
}