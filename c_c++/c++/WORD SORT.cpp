#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector <pair <int,string>>v;
    vector <pair <int,string>>::iterator it;   
    vector <pair <int,string>>::iterator it2;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(make_pair(s.length(),s));
    }
    sort(v.begin(),v.end());
    for(it=v.begin();it2!=v.end();){
        it2=++it;
        it--;
        if(it->second==it2->second)
        v.erase(it2);
        else it=it2;
    }
    for(int i=0;i<v.size();i++)
    cout<<v[i].second<<'\n';
    return 0;
}