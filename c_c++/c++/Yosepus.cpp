#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector <int> v(n);
    int cnt[n];
    for(int i=0;i<n;i++)
    v[i]=i+1;
    int era=0;
    int n2=n;
    for(int i=0;i<n;i++){
        era=(era+k)%n2;
        if(era==0)
        era=n2;
        cnt[i]=*(v.begin()+era-1);
        v.erase(v.begin()+era-1);
        n2--;
        era--;
    }
    cout<<'<';    
    for (int i=0;i<n;i++){
        if(i==n-1)
        cout<<cnt[i]<<'>';
        else
        cout<<cnt[i]<<", ";
    }
    return 0;
}