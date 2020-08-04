#include <iostream>
#include <queue>
using namespace std;
queue<char>q;
void cut(int arr[64][64],int x,int y,int n){
    while(n>0){
        int chk=arr[y][x];
        int ch=1;
        for(int i=y;i<y+n;i++){
            for(int j=x;j<x+n;j++){
                if(arr[i][j]!=chk){
                    ch=0;
                    break;
                }
            }
            if(ch==0)
            break;    
        }
        if(ch==1){
            if(chk==1){
                q.push('1');
            }
            else q.push('0');
            break;
        }
    n=n/2;
    q.push('(');
    cut(arr,x,y,n);
    cut(arr,x+n,y,n);
    cut(arr,x,y+n,n);
    cut(arr,x+n,y+n,n);
    q.push(')');
    break;
    }
}
int main() {
    int n;
    cin>>n;
    int arr[64][64];
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            arr[i][j]=s[j]-48;
        }
    }
    cut(arr,0,0,n);
    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }
    return 0;
}