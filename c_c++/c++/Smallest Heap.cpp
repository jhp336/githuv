#include <iostream>
#include <set>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio;
    int n;
    multiset<int>m;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==0){
            if(!m.empty()){
                cout<<*m.begin()<<'\n';
                m.erase(m.begin());
            }
            else cout<<0<<'\n';
        }
        else m.insert(a);
    }
}