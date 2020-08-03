#include<iostream>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    cin>>m;
    int s[21]{0};
    for(int i=0;i<m;i++){
        string c;
        int n;
        cin>>c;
        if(c!="all"&&c!="empty")
        cin>>n;
        if(c=="add")
        s[n]=1;
        else if(c=="remove")
        s[n]=0;
        else if(c=="check"){
            if(s[n]==1)
            cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else if (c=="toggle"){
            if(s[n]==1)
            s[n]=0;
            else s[n]=1;
        }
        else if(c=="all"){
            for(int j=0;j<20;j++)
            s[j+1]=1;
        }
        else if(c=="empty"){
            for(int j=0;j<20;j++)
            s[j+1]=0;
        }
    }
    return 0;
}