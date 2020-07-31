#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n,tmp;
    cin>>n;
    queue<int>q;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="push"){
            cin>>tmp;
            q.push(tmp);
        }
        else if(s=="front"){
            if(q.size()==0)
            cout<<"-1"<<'\n';
            else
            cout<<q.front()<<'\n';
        }
        else if(s=="back"){
            if(q.size()==0)
            cout<<"-1"<<'\n';
            else
            cout<<q.back()<<'\n'; 
        }
        else if(s=="size")
        cout<<q.size()<<'\n';
        else if(s=="empty"){
            if(q.empty())
            cout<<"1"<<'\n';
            else cout<<"0"<<'\n';
        }
        else if(s=="pop"){
            if(q.size()==0)
            cout<<"-1"<<'\n';
            else{
                cout<<q.front()<<'\n';
                q.pop();
            }
        }
    }
    return 0;
}