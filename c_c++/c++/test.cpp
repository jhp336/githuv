#include <iostream>
#include<vector>
using namespace std;
int main() {
    int n=6;
    int left[n]={3,2,0,0,1,0};
    vector <int> v;
    for(int i=n;i>0;i--){
        if(i==n)
        v.push_back(i);
        else v.insert(v.begin()+left[i-1],i);
    }
    for(int i=0;i<n;i++)
    cout<<v[i]<<' ';
    return 0;
}