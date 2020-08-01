#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m,cnt=0;
        cin>>n>>m;
        vector<int> im;
        queue<int>pr;
        for(int j=0;j<n;j++){
            int imp;
            cin>>imp;
            im.push_back(imp);
            pr.push(j);
        }
        for(int j=0;!pr.empty();j++){
            if(j>=n)
            j=j-n;
            if(im[j]!=-1)
            {
                int mx=0;
                for(int k=0;k<n;k++){
                    if(im[j]==max(im[j],im[k]))
                    mx=1;
                    else {
                        mx=0;
                        break;
                    }
                }
                if(mx==1){
                    cnt++;
                    if(pr.front()==m){
                        cout<<cnt<<'\n';
                        break;
                    }
                    pr.pop();
                    im[j]=-1;
                }
                else {
                    pr.pop();
                    pr.push(j);
                }
        
            } 
 
        }
    }
    return 0;
}