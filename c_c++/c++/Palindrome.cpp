#include <iostream>
#include <cstring>
using namespace std;

int main() {
    
    while(1) {
        char num[6];
        int a=0;
        cin>>num;
        if(num[0]=='0')
        break;
        for(int i=0;i<strlen(num)/2;i++){
            if (num[i]==num[strlen(num)-1-i])
            a=0;
            else a=1;
        }
        if (a==1)
        printf("no\n");
        else printf("yes\n");
    }
    return 0;
}