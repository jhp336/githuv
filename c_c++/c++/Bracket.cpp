#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int x=0;x<t;x++){
        string s;
        cin>>s;
        vector <int> v;
        int ch=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
            v.push_back(1);
            else{
                if(v.empty()){
                    cout<<"NO\n";
                    ch=1;
                    break;
                }
                else v.pop_back();
            }
        }
        if(ch==0){
            if(v.empty())
            cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}