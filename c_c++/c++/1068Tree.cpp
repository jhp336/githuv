#include <iostream>
#include <vector>
using namespace std;
int leaf(vector<vector<int>>& v,int num){
    if(v[num].empty())
    return 1;
    int sum=0;
    for(int i=0;i<v[num].size();i++){
        sum=sum+leaf(v,v[num][i]);
    }
    return sum;
}
int main(){
    int n,remove,root;
    cin>>n;
    int parent[n];
    vector<vector<int>>v(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x!=-1)
        v[x].push_back(i);
        else root=i;
        parent[i]=x;
    }
    cin>>remove;
    int all=leaf(v,root);
    int leafn=leaf(v,remove);
    int par=parent[remove];
    if(v[par].size()==1)
    cout<<all-leafn+1;
    else cout<<all-leafn;
}