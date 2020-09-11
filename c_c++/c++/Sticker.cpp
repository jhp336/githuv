#include <iostream>
#include <set>
#include <cstring>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
        int n,cnt=0;
        cin>>n;
        int arr[4][n+2];
        memset(arr,-1,sizeof(arr));
        multiset <int,greater<int>> s;
        for(int i=1;i<3;i++){
            for(int j=1;j<n+1;j++){
                cin>>arr[i][j];
                s.insert(arr[i][j]);
            }
        }
        while(s.empty()==0){
            int ck=0;
            for(int i=1;i<3;i++){
                for(int j=1;j<n+1;j++){
                    if(s.empty()){
                        ck=1;
                        break;
                    }
                    if(arr[i][j]==*s.begin()){
                        ck=1;
                        cnt=cnt+*s.begin();
                        arr[i][j]=0;
                        s.erase(s.begin());
                        if(arr[i-1][j]!=-1){
                            s.erase(s.find(arr[i-1][j]));
                            arr[i-1][j]=-1;
                        }
                        if(arr[i+1][j]!=-1){
                            s.erase(s.find(arr[i+1][j]));
                            arr[i+1][j]=-1;
                        }
                        if(arr[i][j-1]!=-1){
                            s.erase(s.find(arr[i][j-1]));
                            arr[i][j-1]=-1;
                        }
                        if(arr[i][j+1]!=-1){
                            s.erase(s.find(arr[i][j+1]));
                            arr[i][j+1]=-1;
                        }
                        break;
                    } 
                }
                if(ck==1)
                break;
            }         
        }
        cout<<cnt<<'\n';
    }
    return 0;
}