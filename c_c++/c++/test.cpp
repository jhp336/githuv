#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int> b){
    if(a.first==b.first)
    return a.second>b.second;
    else return a.first>b.first;
}
int main() {
    
    int n,cnt=0,chk=0,tmp;
    n=4;
    vector<pair<int,int>>m;
    for(int i=0;i<n;i++){
        int v=4;
        if(i==0)
        tmp=v;
        m.push_back(make_pair(v,i));
    }
    sort(m.begin(),m.end(),cmp);
    vector<pair<int,int>>::iterator it;
    for(it=m.begin();it->first>=tmp;it++){
        chk=0;
        while(it->first>tmp){
            it->first--;
            tmp++;
            cnt++;
        }
        if(it->first==tmp){
            chk=1;
        }
    }
    if(chk==1)
    cnt++;
    cout<<cnt;
    return 0;
}