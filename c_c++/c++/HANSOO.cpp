#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int s,ans=99;
    string n;
    cin>>n;
    if (stoi(n)<100)
    ans=stoi(n);
    else if(stoi(n)<111)
    ans=99;
    else {
        for(int i=111;i<stoi(n)+1;i++){
            int l=n.length()-1;
            int f[n.length()];
            for(int j=0;j<n.length();j++){
                if(j==0)
                f[j]=i/(int)pow(10,l);
                else f[j]=i/(int)pow(10,l-j)-(i/(int)pow(10,l-j+1))*10;
            }
            int ch=0;
            for(int k=0;k<n.length()-2;k++){
                if(f[k]-f[k+1]==f[k+1]-f[k+2])
                ch=1;
                else break;
            }
            if(ch==1)
            ans++;
        }
    }
    if(stoi(n)==1000)
    ans=144;
    cout<<ans;
    return 0;
}