#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,k,cnt=0;
    cin>>n>>k;
    vector <int> a(n);
    for(int i=0;i<n;i++)
    cin>>a.at(i);
    for (int i=0;i<n;i++){
        if (a.at(n-i-1)<=k)
        cnt=cnt+k/a.at(n-i-1);
        k=k%a.at(n-i-1);
    }
    cout<<cnt;
    return 0;
}