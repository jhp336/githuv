#include<iostream>
#include <vector>
using namespace std;
int n=8,cnt1=0,cnt2=0;
void cut(vector <vector<int>>v,int x,int y,int tmp){
    int chk,br=1,cnt=0;
    while (1){
        chk=v[y][x];
        for(int i=y;i<y+tmp;i++){
            for(int j=x;j<x+tmp;j++){
                if(v[i][j]!=chk){
                    br=0;
                    break;
                }
            }
            if(br==0)
            break;
        }
        if(br==1){
                if(chk==0)
                cnt1++;
                else 
                cnt2++;
                break;
            }
        tmp=tmp/2;
        if(tmp==0)
        break;
        cut(v,x,y,tmp);
        cnt++;
        cut(v,x+tmp,y,tmp);
        cnt++;
        cut(v,x,y+tmp,tmp);
        cnt++;
        cut(v,x+tmp,y+tmp,tmp);
        cnt++;
        if(cnt==4)
        break;
    }
}
int main() {
    vector <vector<int>>v{{1,1,0,0,0,0,1,1},{1,1,0,0,0,0,1,1},{0,0,0,0,1,1,0,0},{0,0,0,0,1,1,0,0},{1,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1},{0,0,1,1,1,1,1,1},{0,0,1,1,1,1,1,1}};
    
    cut(v,0,0,n);
    cout<<cnt1<<'\n'<<cnt2;
    return 0;
}