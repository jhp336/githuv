#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int n;
void find(pair<int,int>s,char m[20][20],int size){
    int dis[4]={s.first+s.second,s.first+(n-s.second),n-s.first+n-s.second,n-s.first+s.second};
    sort(dis,dis+3,greater<int>());
    while(dis[0]>0){
        
    }
}
int main() {
    int time=0,m=0,size=2;
    cin>>n;
    char f[20][20];
    pair<int,int> shark;
    vector <pair<int,int>> fish;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>f[i][j];
            if(f[i][j]!='0'&&f[i][j]!='9'){
                m++;
                fish.push_back(make_pair(i,j));
            }
            else if(f[i][j]=='9'){
                shark.first=i;
                shark.second=j;
            }
    }
    for(int i=0;i<m;i++){
        
    }

}