#include <iostream>
using namespace std;
char tmp;
void pick(char s[102][102],int i,int j){
    if(s[i][j]!=tmp)
    return ;
    s[i][j]='X';
    pick(s,i,j-1);
    pick(s,i+1,j);
    pick(s,i,j+1);
    pick(s,i-1,j);
}
int main() {
    int n,cnt=0,cnt2=0;
    cin>>n;
    char s[102][102]={' ', };
    char s2[102][102]={' ', };
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            char a;
            cin>>a;
            s[i][j]=a;
            if(a=='G')
            a='R';
            s2[i][j]=a;
        }
        
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(s[i][j]!='X'){
                tmp=s[i][j];
                pick(s,i,j);
                cnt++;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(s2[i][j]!='X'){
                tmp=s2[i][j];
                pick(s2,i,j);
                cnt2++;
            }
        }
    }
    
    cout<<cnt<<' '<<cnt2;
    return 0;
}