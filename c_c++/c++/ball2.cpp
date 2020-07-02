#include <iostream>
using namespace std;

int main() {
    int c[3]={1,0,0};
    
        int a=0;
        int b=1;
        int temp=0;
        temp=c[a];
        c[a]=c[b];
        c[b]=temp; 
    
    for (int i=0;i<3;i++) {
    cout<<c[i];
    }
}