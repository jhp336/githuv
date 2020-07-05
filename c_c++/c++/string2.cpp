#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    for (int i=0;i<t;i++){
        int r;
        char ss[20];
        cin>>r>>ss;
        for (int j=0;j<strlen(ss);j++)
            for (int k=0;k<r;k++)
                cout<<ss[j];
        
        
        cout<<endl;
    }
    return 0;

}