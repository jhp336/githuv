#include <iostream>
#include <map>
#include <set>
using namespace std;
int main() {
    int sum=0;
    set<pair<int,int>>m;
    for(int i=0;i<8;i++){
        int s;
        cin>>s;
        m.insert(make_pair(s,i+1));
    }
    set<pair<int,int>>::iterator it;
    set<int>s;
    int ch=0;
    for(it=--m.end();ch<5;it--){
        sum=sum+it->first;
        s.insert(it->second);
        ch++;
    }
    set<int>::iterator itt;
    cout<<sum<<'\n';
    for(itt=s.begin();itt!=s.end();itt++)
    cout<<*itt<<' ';
    return 0;
}