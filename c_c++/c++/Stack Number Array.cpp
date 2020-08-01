#include <iostream>
#include <stack>
#include<queue>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio;
    int n;
    cin>>n;
    queue<int>arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push(a);
    }
    stack<int>s;
    queue<string>q;
    int i=1;
    while(!arr.empty()){
        if(s.empty()||s.top()!=arr.front()){
            s.push(i);
            q.push("+\n");
        }
        if(s.top()==arr.front()){
            q.push("-\n");
            arr.pop();
            s.pop();
            if(s.empty()||s.top()!=arr.front())
            i++;
            
        }
        else i++;
        if(i>n+1){
            cout<<"NO";
            return 0;
        }
    }
    int tmp=q.size();
    for(int i=0;i<tmp;i++){
        cout<<q.front();
        q.pop();
    }
    return 0;
}