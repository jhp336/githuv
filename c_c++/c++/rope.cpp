#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,ans=0;
    cin>>n;
    vector <int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++)
    cin>>a.at(i);
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<n;i++)
    if(ans<a.at(i)*(i+1))
    ans=a.at(i)*(i+1);
    
    cout<<ans;
        
    
    return 0;
}