#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
using namespace std;
bool cmp(pair<int,string>p,pair<int,string> p2){
    if(p.first==p2.first)
    return p.second>p2.second;
    return p.first<p2.first;
}
int main() {
    int n;
    cin>>n;
    map <string,int> m;
    vector<pair<int,string>> v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(m.find(s)==m.end())
        m.insert(make_pair(s,1));
        else m[s]++;
        v.push_back(make_pair(m[s],s));
    }
    sort(v.begin(),v.end(),cmp);
    cout<<v.back().second;
    return 0;
}