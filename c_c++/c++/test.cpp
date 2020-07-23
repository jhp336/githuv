#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int ans;
    vector <pair <int,int>> v{{0,4000},{0,4000},{0,4000}};
    for(int i=2;i<v.size();i++){
        if(v[v.size()-1].first==v[v.size()-i].first)
        ans=v[v.size()-i+1].second;
        else{
            break;
            ans=v[v.size()-1].second;
        }
    }
    cout<<ans;
}
