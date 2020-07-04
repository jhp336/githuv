#include <iostream>
using namespace std;

int main() {
    int c[3]={1,0,0};
    int m,a,b;
    cin>>m;
    for(;m>0;m--){
        cin>>a>>b;
        int temp=0;
        temp=c[a-1];
        c[a-1]=c[b-1];
        c[b-1]=temp; 
    }
    for (int i=0;i<3;i++) 
    if (c[i]==1)
    cout<<i+1<<endl;
    
    return 0;
}