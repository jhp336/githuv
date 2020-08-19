#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,cnt=0,chk=0,tmp;
    cin>>n;
    vector<int>m;
    cin>>tmp;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<n;i++){
        int v;
        cin>>v;
        m.push_back(v);
    }
    sort(m.begin(),m.end(),greater<int>());
    while(tmp<=m.front()){
        m.front()--;
        tmp++;
        cnt++;
        sort(m.begin(),m.end(),greater<int>());
    }
    cout<<cnt;
    return 0;
}