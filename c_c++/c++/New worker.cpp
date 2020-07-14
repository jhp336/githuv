#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin>>t;
    vector <int> a;
    for (int i=0;i<t;i++){
        int n;
        cin>>n;
        int ans=n;
        int g1;
        vector <int> v(n); 
        for (int i=0;i<n;i++){
            cin>>g1>>v[g1-1];
        }
        int m=v[0];
        for(int i=1;i<n;i++){
            if(m>v[i])
            m=v[i];
            else ans--;
        }
        a.push_back(ans);
    }
    for (int i=0;i<t;i++)
    cout<<a[i]<<endl;
    return 0;
}