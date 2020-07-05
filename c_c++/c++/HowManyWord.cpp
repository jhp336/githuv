#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char w[100];
    int now=0;
    cin.getline(w,100);
   
    for(int i=0;i<strlen(w);i++){
        if(w[i]==' ')
        now++;
    }
    if(w[0]==' ')
    now--;
    if(w[strlen(w)-1]==' ')
    now--;
    cout<<now+1<<endl;
    
    return 0;

}