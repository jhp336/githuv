#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vector <int> v;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        v.push_back(input);
    }
    sort(v.begin(),v.end());
    cout<<v[k-1];
}