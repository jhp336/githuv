#include <iostream>
using namespace std;

int main() {
    int n=6;
    
    int c[6]={};
    for(int i=0;i<n;i++)
    c[i]=i+1;
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1;j++){
            c[j]=c[j+1];
        }
        c[n-1]=c[0];
        for(int j=0;j<n-1;j++){
            c[j]=c[j+1];
        }
        
    }
    cout<<c[0]<<endl;
}