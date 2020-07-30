#include <iostream>
#include <vector>
using namespace std;
void curve(vector <vector<int>>& a,int g,int startx,int starty,int dir){
    if(g==0){
        a[startx][starty]=1;
        if (dir==0){
            a[startx+1][starty]=1;
            startx=startx+1;
        }
        else if(dir==1){
            a[startx][starty-1]=1;
            starty=starty-1;
        }
        else if(dir==2){
            a[startx-1][starty]=1;
            startx=startx-1;
        }
        else {
            a[startx][starty+1]=1;
            starty=starty+1;
        }
        dir++;
        if(dir==4)
        dir=0;
    }
    else {
        curve(a,g-1,startx,starty,dir);
        if (dir==0){
            startx=startx+1;
        }
        else if(dir==1){
            starty=starty-1;
        }
        else if(dir==2){
            startx=startx-1;
        }
        else {
            starty=starty+1;
        }
        dir++;
        if(dir==4)
        dir=0;
        curve(a,g-1,startx,starty,dir);
    }
}
int main() {
    int n,cnt=0;
    vector <vector<int>> a(101,vector <int>(101));
    curve(a,1,2,2,0);
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(a[i][j]==1&&a[i+1][j]==1&&a[i][j+1]==1&&a[i+1][j+1]==1)
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}   