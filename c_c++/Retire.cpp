#include <iostream>
#include <vector>
using namespace std;    
int n;
void pick(vector <pair<int,int>>& v,int start,int day,int money){
    for(int i=0;i<n;i++){
        day=i+v[i].first;
        if(day<n){
            money=money+v[i].second;
            i=i+v[i].first;
        }
        else break;
    }
    
}
int main() {
    int money;
    cin>>n;
    vector <pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    pick(v,)
}