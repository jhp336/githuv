#include <iostream>
#include <stack>
#include<queue>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio;
    int n,cnt=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    stack<int>s;
    queue<string>q;;
    int i=1;
    while(i<n+1){
        if(s.empty()){
            s.push(i);
            q.push("+\n");
        }
        if(s.top()==arr[cnt]){
            q.push("-\n");
            s.pop();
            cnt++;
            if(i==n)
            break;
        }
        else {
            i++;
            s.push(i);
            q.push("+\n");
        }
    }
    while(!s.empty()){
        if(s.top()==arr[cnt]){
            q.push("-\n");
            s.pop();
            cnt++;
        }
        else {
            cout<<"NO";
            return 0;
        }
    }
    int tmp=q.size();
    for(int i=0;i<tmp;i++){
        cout<<q.front();
        q.pop();
    }
}