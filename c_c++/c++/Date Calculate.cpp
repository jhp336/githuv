#include <iostream>
using namespace std;
int main() {
    int x=1,e,s,m;
    cin>>e>>s>>m;
    
    while(1){
        int a=x%15;
        if(a==0)
        a=15;
        int b=x%28;
        if(b==0)
        b=28;
        int c=x%19;
        if(c==0)
        c=19;

        if(a==e&&b==s&&c==m){
            cout<<x;
            return 0;
        }
        else x++;
    }
}