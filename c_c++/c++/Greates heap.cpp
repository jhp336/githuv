#include <set>
#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,x;
    cin>>n;
    multiset<int>s;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x>0)
        s.insert(x);
        else if(!s.empty()){
            cout<<*--s.end()<<'\n';
            s.erase(--s.end());
        }
        else cout<<'0'<<'\n';
    }
    return 0;
}