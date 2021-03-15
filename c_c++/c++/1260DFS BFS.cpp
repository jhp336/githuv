#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
set<int> dup;
void DFS(vector <set<int>>& vec,int v){
    dup.insert(v);
    set<int>::iterator it;
    for(it=vec[v-1].begin();it!=vec[v-1].end();it++){
        if(dup.find(*it)==dup.end()){
            dup.insert(*it);
            cout<<*it<<' ';
            DFS(vec,*it);
        }
    }
}
void BFS(vector <set<int>>& vec,int v){
    queue <int> q;
    q.push(v);
    set<int>dup;
    dup.insert(v);
    set<int>::iterator it;
    while(!q.empty()){
        int qf=q.front();
        cout<<qf<<' ';
        q.pop();
        it=vec[qf-1].begin();
        for(;it!=vec[qf-1].end();it++){
            if(dup.find(*it)==dup.end()){
                q.push(*it);
                dup.insert(*it);
            }
        }
    }
}
int main(){
    int n,m,v;
    cin>>n>>m>>v;
    vector <set<int>> vec(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        vec[x-1].insert(y);
        vec[y-1].insert(x);
    }
    cout<<v<<' ';
    DFS(vec,v);
    cout<<'\n';
    BFS(vec,v);
}