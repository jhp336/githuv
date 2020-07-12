#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main() {
    int n,cnt=0;
    cin>>n;
    vector<pair <int,int>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].second>>a[i].first;
    }
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