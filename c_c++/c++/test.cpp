#include <set>
#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,x[4]{50,0,30,0};
    n=4;
    multiset<int>s;
    multiset<int>::iterator it;
    for(int i=0;i<n;i++){
        if(x[i]>0)
        s.insert(x[i]);
        else if(!s.empty()){
            it=s.end();
            cout<<*--it<<'\n';
            s.erase(it);
        }
        else cout<<'0'<<'\n';
    }
    return 0;
}