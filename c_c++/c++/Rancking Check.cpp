#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main() {
    int n,score,p,ans=0;
    cin>>n>>score>>p;
    deque <int> dq;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        dq.push_back(k);
    }
    if(dq.empty())
    cout<<"1";
    else if(score<=dq.back()&&n==p){
        cout<<"-1";
    }
    else{
        dq.push_back(score);
        sort(dq.begin(),dq.end(),greater<int>());
        for(int i=0;i<dq.size();i++){
            ans++;
            if(dq[i]==score)
            break;
        }
        cout<<ans;
    }
    return 0;
}