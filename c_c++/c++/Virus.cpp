#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    int n,m;
    cin>>n;
    cin>>m;
    set<int> c;
    set<int>::iterator it;
    vector<pair<int,int>>v;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
        if(v[i].first==1&&v[i].second!=1)
        c.insert(v[i].second);
        else if(v[i].second==1)
        c.insert(v[i].first);
    }
    for(int j=0;j<m;j++){
        for(int i=0;i<m;i++){
            for(it=c.begin();it!=c.end();it++){
                if(v[i].first==*it||v[i].second==*it){
                    c.insert(v[i].second);
                    c.insert(v[i].first);
                    break;
                }
            }
        }
    }
    int ans=c.size();
    if(c.find(1)==c.end())
    cout<<ans;
    else
    cout<<ans-1;
    return 0;
}