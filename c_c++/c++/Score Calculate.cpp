#include <iostream>
#include <map>
#include <set>
using namespace std;
int main() {
    int sum=0;
    map<int,int,greater<int>>m;
    for(int i=0;i<8;i++){
        int s;
        cin>>s;
        m.insert(make_pair(s,i+1));
    }
    map<int,int>::iterator it;
    set<int> n;
    int ch=0;
    for(it=m.begin();ch<5;it++){
        sum=sum+it->first;
        n.insert(it->second);
        ch++;
    }
    cout<<sum<<'\n';
    set<int>::iterator itt;
    for(itt=n.begin();itt!=n.end();itt++)
    cout<<*itt<<' ';
    return 0;
}