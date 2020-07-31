#include <iostream>
#include <queue>
#include <map>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio;
    int n=;

    queue<string>q;
    map <int,int> arr{{1,4},{2,3},{3,6},{4,8},{5,7},{6,5},{7,2},{8,1},};
    
        int cnt,tmp;
        for(int i=1;i<n+1;i++){
            if(i!=arr.begin()->second){
                q.push("+\n");
                cnt=0;
            } 
            else{
                arr.erase(arr.begin());
                if(cnt==0){
                    q.push("+\n-\n");
                    cnt=1;
                    tmp=i;
                }
                else    q.push("-\n");
                if(tmp!=8&&tmp<arr.begin()->second)
                i=tmp;
                else if(tmp!=8&&tmp>arr.begin()->second)
                i=i-2;
            }
        }
        while(!arr.empty()){
            q.push("-\n");
            arr.erase(arr.begin());
            else {
            cout<<"NO";
            return 0;
        }
        }    
        int r=q.size();
        for(int i=0;i<r;i++){
            cout<<q.front();
            q.pop();
        }
    return 0;
}