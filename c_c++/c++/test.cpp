#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main() {
    int n,cnt=0;
    n=9;
    vector<pair <int,int>>a{
        {8,8},{8,5},{4,3},{5,2},{7,2},{8,8},{10,1},{3,3},{10,10}};
    
    sort(a.begin(),a.end());
    int start=a[0].first;
    for (int i=0;i<n;i++){
        if(start<=a[i].second){
        start=a[i].first;
        cnt++;
            }
        }
    cout<<cnt+1;
    return 0;
}