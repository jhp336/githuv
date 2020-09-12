#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m,max,min=0,mid;
    long long cnt;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(max<arr[i])
        max=arr[i];
    }
    while(1){
        cnt=0;
        mid=(max+min)/2;
        for(int i=0;i<n;i++){
            if(arr[i]>mid){
                cnt=cnt+arr[i]-mid;
            }
        }
        if(cnt==m){
            cout<<mid;
            return 0;
        }
        else if(min>=max){
            if(cnt>=m){
                cout<<max;
                return 0;
            }
            else {
                cout<<max-1;
                return 0;
            }
        }
        else if(cnt>m){
            min=mid+1;
        }
        else max=mid-1;
    }
    
    return 0;
}