#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool *arr;
vector<int>* v;
int cnt;
void count(int a){
    arr[a]=true;
    for(int i=0;i<v[a].size();i++){
        int val=v[a][i];
        if(arr[val]==false){
            cnt++;
            count(val);
        }
    }
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    v=new vector<int>[n+1];
    arr=new bool[n+1];
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[y].push_back(x);
    }
    vector<int> ans;
    int max=0;
    for(int i=1;i<n+1;i++){
        cnt=0;
        fill(arr,arr+n+1,false);
        count(i);
        if(cnt==max){
            ans.push_back(i);
        }
        else if(cnt>max){
            max=cnt;
            ans.clear();
            ans.push_back(i);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<' ';
    
}