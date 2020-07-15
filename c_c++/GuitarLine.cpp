#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main() {
    int n,m,pay;
    cin>>n>>m;
    vector <pair<int,int>>v(m);
    vector <int>v2(m);
    for (int i=0;i<m;i++){
        cin>>v[i].first>>v[i].second;
        v2[i]=v[i].second;
    }        
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    pay=v2[0]*n;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
        int pay2=v[i].first*(n/6)+v[j].second*(n%6);
        if(pay>pay2)
        pay=pay2;
        }
        int pay3=v[i].first*(n/6+1);
        if (pay>pay3)
        pay=pay3;
    }
    cout<<pay;
    return 0;
}