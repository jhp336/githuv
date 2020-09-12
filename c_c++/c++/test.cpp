#include <iostream>
#include <set>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m,cnt;
    cin>>n>>m;
    multiset<int,greater<int>>s;
    multiset<int,greater<int>>::iterator it,itt;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    s.insert(0);
    int i=1;
    for(it=++s.begin();it!=s.end();it++){
        cnt=0;
        for(itt=s.begin();itt!=it;itt++){
            cnt=cnt+*itt-*it;   
        }
            if(cnt==m){
            cout<<*it;
            return 0;
        }
        else if(cnt>m){
            int sub=cnt-m;
            cout<<*it+sub/i;
            return 0;
        }
        i++;
    }
    return 0;
}