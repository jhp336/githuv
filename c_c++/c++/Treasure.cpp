#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    int n,sum=0;
    cin>>n;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        a.push_back(c);
    }
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        b.push_back(c);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
    for(int i=0;i<n;i++){
        sum=sum+a[i]*b[i];
    }
    cout<<sum;
}