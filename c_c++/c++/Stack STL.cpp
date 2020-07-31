#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio;
    int n,tmp;
    cin>>n;
    stack<int>a;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="push"){
            cin>>tmp;
            a.push(tmp);
        }
        else if(s=="pop"){
            if(a.size()==0)
            cout<<"-1"<<'\n';
            else {
                cout<<a.top()<<'\n';
                a.pop();
            }
        }
        else if(s=="size")
        cout<<a.size()<<'\n';
        else if(s=="empty"){
            if(a.empty())
            cout<<"1"<<'\n';
            else cout<<"0"<<'\n';
        }
        else if(s=="top"){
            if(a.size()==0)
            cout<<"-1"<<'\n';
            else cout<<a.top()<<'\n';
        }
    }
    return 0;
}