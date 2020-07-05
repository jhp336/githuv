#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int acc=0;
        int count=0;    
        string ans;
        cin>>ans;
        for(int j=0;j<ans.length();j++){
        if(ans[j]=='O'){
        acc++;
        count=count+acc;
        }
        else acc=0;
    }
    cout<<count<<endl;
    }
    return 0;
}
