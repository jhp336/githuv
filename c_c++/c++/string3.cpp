#include <iostream>
#include <string>
using namespace std;
int main (){
    string a,b;
    cin>>a>>b;
    int ans=a.size();
    for (int i=0;i<=b.size()-a.size();i++){
        int dif=0;
        for(int j=0;j<a.size();j++){
        if(a[j]!=b[i+j])
        dif++;
        }
        if(dif<=ans)
        ans=dif;
    }

    cout<<ans;
    return 0;
}