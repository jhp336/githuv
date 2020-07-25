#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n;
    vector <int> nn(n);
    for (int i=0;i<n;i++)
    cin>>nn[i];
    cin>>m;
    vector <int>mm(m);
    for(int i=0;i<m;i++)
    cin>>mm[i];
    int cnt[m]={0, };
    int j=0;
    sort(nn.begin(),nn.end());
    for(int i=0;i<m;i++){
        int start=0;
        int end=nn.size()-1;
        int mid;
        while(start<=end){
            mid=(end+start)/2;
            if(mm[i]==nn[mid]){
                cnt[i]=1;
                break;
            }
            else if(mm[i]>nn[mid])
            start=mid+1;
            else end=mid-1;
        }
    }
    for(int i=0;i<m;i++)
    cout<<cnt[i]<<'\n';

    return 0;
}