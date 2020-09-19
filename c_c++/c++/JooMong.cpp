#include <iostream>
#include <set>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    set<int> s;
    set<int>::iterator it;
    set<int>::iterator itt;
    int m;
    cin>>m;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        s.insert(a);
    }
    s.insert(100001);
    if(m>200000){
        cout<<0;
        return 0;
    }
    int cnt=0;
    for(it=s.begin();it!=--s.end();it++){
        if(s.find(m-(*it))!=s.end()&&s.find(m-(*it))!=it){
            cnt++;
            s.erase(s.find(m-(*it)));
        }
    }
    cout<<cnt;
    return 0;
}