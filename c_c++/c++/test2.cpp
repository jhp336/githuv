#include <iostream>
using namespace std;
char tmp;
void pick(string s[102],int i,int j){
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
    n=5;
    string s[102]={" "," RRRBB "," GGBBB "," BBBRR "," BBRRR "," RRRRR "," "};
    string s2[102]={" "," "};
    string s3[102]={"", };
    for(int i=1;i<n+1;i++){
        for (int j=1;j<n+1;j++)
        s3[i][j]='t';
    }
    for(int i=0;i<n+2;i++){
        s2[i].assign(s[i]);
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
            if(s2[i][j]=='G')
            s2[i][j]='R';
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