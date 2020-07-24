#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,ans1=1,ans2=1;
    cin>>n;
    vector<string>v;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(v[i][j]!=v[i][j+1]){
                ans1++;
                ans2++;
                if((v[i][j]=='G'&&v[i][j+1]=='R')||(v[i][j]=='R'&&v[i][j+1]=='G'))
                ans2--;
            }
        }
        ans1++;
        ans2++;
        }
        ans1--;
        ans2--;
    for(int i=0;i<n-1;i++){
        for (int j=1;j<n;j++){
            if(v[i][j]==v[i+1][j]&&(v[i][j-1]!=v[i][j]||v[i+1][j-1]!=v[i+1][j])){
                if(i>0&&v[i-1][j-1]==v[i][j]==v[i+1][j-1]){
                ans1++;
                ans2++;
                }
                ans1--;
                ans2--;
            }
            if(((v[i][j]=='G'&&v[i+1][j]=='R')||(v[i][j]=='R'&&v[i+1][j]=='G'))&&(v[i][j-1]=='B'||v[i+1][j-1]=='B'))
                ans2--;
        }
        if(v[i][0]==v[i+1][0]){
            ans1--;
            ans2--;
        }
        if((v[i][0]=='G'&&v[i+1][0]=='R')||(v[i][0]=='R'&&v[i+1][0]=='G'))
        ans2--;
    }
    cout<<ans1<<' '<<ans2;
}