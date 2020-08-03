#include <iostream>
#include <map>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int n,sum=0,tmp=1;
        cin>>n;
        map<string,int>m;
        for(int i=0;i<n;i++){
            string s1,s2;
            cin>>s1>>s2;
            if(m.find(s2)==m.end())
            m.insert(make_pair(s2,1));
            else m[s2]++;
        }
        int size=m.size();
        for(int i=0;i<size;i++){
            tmp=(m.begin()->second+1)*tmp;
            m.erase(m.begin());
        }
        sum=tmp-1;
        cout<<sum<<'\n';
    }
    return 0;
}