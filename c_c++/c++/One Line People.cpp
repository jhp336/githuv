#include <iostream>
#include<vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    int left[n];
    vector <int> v;
    for(int i=0;i<n;i++){
        cin>>left[i];
    }
    for(int i=n;i>0;i--){
        if(i==n)
        v.push_back(i);
        else v.insert(v.begin()+left[i-1],i);
    }
    for(int i=0;i<n;i++)
    cout<<v[i]<<' ';
    return 0;
}