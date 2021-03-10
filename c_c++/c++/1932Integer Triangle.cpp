#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int>v;
    int arr[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            int a;
            cin>>a;
            v.push_back(a);
        }
    }int start=0;
    for(int i=1;i<n;i++){
        if(i!=n-1){
            v[start+i]=v[start]+v[start+i];
            for(int j=0;j<i-1;j++){
                if(v[start+j]>v[start+j+1])
                v[start+i+j+1]=v[start+j]+v[start+i+j+1];
                else
                v[start+i+j+1]=v[start+j+1]+v[start+i+j+1];
            }
            v[start+i+i]=v[start+i-1]+v[start+i+i];
            start=start+i;
        }
        else{
            arr[0]=v[start]+v[start+i];
            for(int j=0;j<i-1;j++){
                if(v[start+j]>v[start+j+1])
                arr[j+1]=v[start+j]+v[start+i+j+1];
                else
                arr[j+1]=v[start+j+1]+v[start+i+j+1];
            }
            arr[n-1]=v[start+i-1]+v[start+i+i];
        }
    }
    sort(arr,arr+n,greater<int>());
    cout<<arr[0];
}