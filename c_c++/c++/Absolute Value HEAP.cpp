#include <iostream>
#include <map>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    multimap<int,int>m;                
    multimap<int,int>::iterator it;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y,cnt=0;
        cin>>x;
        if(x!=0){
            if(x<0)
            y=x*-1;
            else y=x;
            m.insert(make_pair(y,x));
        }
        else {
            if(m.empty())
            cout<<0<<'\n';
            else{
                for(it=m.begin();it->first==m.begin()->first;it++){
                    if(it==m.end())
                    break;
                    if(it->second<0){
                        cout<<it->second<<'\n';
                        m.erase(it);
                        cnt=1;
                        break;
                    }
                }
                if(cnt==0){
                    cout<<m.begin()->second<<'\n';
                    m.erase(m.begin());
                }
            }
        }
    }
    return 0;
}