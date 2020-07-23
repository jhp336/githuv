#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath> 
using namespace std;
int main() {
    double n,sum=0;
    double ans[4];
    cin>>n;
    vector <int> v;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
        sum=sum+tmp;
    }
    ans[0]=round((double)(sum/n));
    if(ans[0]==-0)
    ans[0]=0;
    sort(v.begin(),v.end());
    ans[1]=v[n/2];
    vector <pair <int,int>>v2(v.size());
    v2[v.size()-1].second=v[v.size()-1];
    v2[v.size()-1].first=0;
    int cnt=0;    
    for(int i=0;i<v.size()-1;i++){
        v2[i].second=v[i];
        if(v2[i].second==v[i+1]){
            cnt++;
            v2[i].first=cnt;
        }
        else {
            cnt=0;
            v2[i].first=cnt;
        }
    }
    sort(v2.begin(),v2.end());
    for(int i=2;i<=v.size();i++){
        if(v2[v.size()-1].first==v2[v.size()-i].first)
        ans[2]=v2[v.size()-i+1].second;
        else{
            if(i==2){
                ans[2]=v2[v.size()-1].second;
                break;
            }
            else
            break;
        }
    }
    if(v.size()==1)
    ans[2]=v[0];
    ans[3]=v[v.size()-1]-v[0];
    for (int i=0;i<4;i++)
    cout<<ans[i]<<'\n';
    return 0;
}