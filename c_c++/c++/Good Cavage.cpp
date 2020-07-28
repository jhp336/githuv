#include <iostream>
using namespace std;
void pick(int c[52][52],int i,int j){
    if(c[i][j]==0)
    return ;
    c[i][j]=0;
    pick(c,i,j-1);
    pick(c,i-1,j);
    pick(c,i,j+1);
    pick(c,i+1,j);

}
int main() {
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        int m,n,k;
        cin>>m>>n>>k;
        int c[52][52]={0, };
        for(int j=0;j<k;j++){
            int a,b;
            cin>>a>>b;
            c[b+1][a+1]=1;
        }
        int cnt=0;
        for(int j=1;j<n+1;j++){
            for(int l=1;l<m+1;l++){
                if(c[j][l]==1){
                    pick(c,j,l);  
                    cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}