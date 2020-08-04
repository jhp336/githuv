#include <iostream>
#include<vector>
using namespace std;
int dist(pair<int,int>a,pair<int,int>b){
        int tmp=a.first-b.first;
        if(tmp<0)
        tmp=tmp*(-1);
        int tmp2=a.second-b.second;
        if(tmp2<0)
        tmp2=tmp2*(-1);
        return tmp+tmp2;
}
int main() {
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int n,dis,tmp,tmp2;
        cin>>n;
        vector<pair<int,int>>v;
        pair<int,int>start;
        pair<int,int>end;
        cin>>start.first>>start.second;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            v.push_back(make_pair(a,b));
        }
        cin>>end.first>>end.second;
        if(dist(start,end)<=1000){
            cout<<"happy\n";
            return 0;
        }
        else {
            vector<pair<int,int>>tmp;
            for(int i=0;i<n;i++){
                v.push_back(make_pair(i))
            }
            for(int i=1;i<v.size();i++){
                if(dist(v[v.size()-1-i],*v.end())>1000){

                }
            }
        }
    }
}