#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main() {
    int n,m,cnt=0;
    cin>>n>>m;
    vector<string> ans;
    vector <string> v,vv;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        vv.push_back(s);
    }
    for(int i=0;i<m;i++){
        int start=0,end=n-1;
        while(start<=end){
            int tmp=(start+end)/2;
            if(vv[i]==v[tmp]){
                cnt++;
                ans.push_back(vv[i]);
                break;
            }
            else if(vv[i]<v[tmp]){
                end=tmp-1;
            }
            else start=tmp+1;
        }
    }
    sort(ans.begin(),ans.end());
    cout<<cnt<<'\n';
    for(int i=0;i<cnt;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}