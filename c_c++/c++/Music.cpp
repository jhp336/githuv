#include <iostream>
#include <string>
using namespace std;

int main() {
    string a[8];
    for(int i=0;i<8;i++)
    cin>>a[i];
    int check=0;
    int check2=0;
    
    for(int i=0;i<8;i++){
        if(a[i].at(0)-'0'==i+1)
        check++;
        
        else if(a[i].at(0)-'0'==8-i)
        check2++;
    }
    
    if(check==8)
    cout<<"ascending";
    else if(check2==8)
    cout<<"descending";
    else cout<<"mixed";
    return 0;
}