#include<iostream>
using namespace std;
int main() {
    int n,m,cnt=0;
    cin>>n>>m;
    char va[n][m];
    char vb[n][m];
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++)
        va[i][j]=s[j];
    }
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++)
        vb[i][j]=s[j];
    }
    for (int i=0;i<n-2;i++){
        for (int j=0;j<m-2;j++){
            if(va[i][j]!=vb[i][j]){
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if (va[k][l]=='0')
                        va[k][l]='1';
                        else va[k][l]='0';
                    }
                }
                cnt++;
            }
        }
    }   
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (va[i][j]!=vb[i][j])
            cnt=-1;
        }
    }
    cout<<cnt;
    return 0;

}