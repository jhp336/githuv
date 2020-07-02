#include <iostream>
using namespace std;

int main() {
    int i=0;
    int a=0, b=0;
    cin>>i;
    for(int l=i;l>0;l--){
        cin>>a>>b;
        int k=1;
        for(int m=0;m<b;m++)
        k=a*k%10;
        if(k==0)
        k=10;
        cout<<k<<endl;
    }

    return 0;

}