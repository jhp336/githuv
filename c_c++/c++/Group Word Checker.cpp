#include <iostream>
#include <set>
using namespace std;
int main(){ 
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        string s;
        cin>>s;
        set<char>w;
        char tmp;
        for(int j=0;j<s.length();j++){
            if(w.find(s[j])==w.end()){
                w.insert(s[j]);
                tmp=s[j];
            }
            else if(tmp!=s[j]){
                break;
            }
            if(j==s.length()-1)
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}