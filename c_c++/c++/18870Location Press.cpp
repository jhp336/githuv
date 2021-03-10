#include <iostream>
#include <map>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int arr[n];
    map<int,int> m;
    map<int,int>::iterator it;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m.insert(pair<int,int>(arr[i],0));
    }
    int i=0;
    for(it=m.begin();it!=m.end();it++){
        m[it->first]=i;
        i++;
    }
    for(int i=0;i<n;i++){
        it=m.find(arr[i]);
        cout<<it->second<<' ';
    }

}