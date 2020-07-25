#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct body{
    int no;
    int w;
    int h;
};
bool cmp(const body&a,const body&b){
    return a.w<b.w;
}
int main() {
    int n;
    cin>>n;
    int cnt[n];
    vector <body> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].w>>v[i].h;
        v[i].no=i;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++){
        int c=0;
        for(int j=i+1;j<n;j++){
            if(v[i].h<v[j].h&&v[i].w<v[j].w)
            c++;
        }
        cnt[v[i].no]=c+1;
    }
    for(int i=0;i<n;i++){
        if(i==n-1)
        cout<<cnt[i];
        else
        cout<<cnt[i]<<' ';
    }
    return 0;
}