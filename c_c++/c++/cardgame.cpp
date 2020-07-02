#include <iostream>
using namespace std;

int main() {
    int a[10];
    int b[10];
    int as=0, bs=0;
    int d=0;
    for (int i=0;i<10;i++)
    cin>>a[i];
    for (int i=0;i<10;i++)
    cin>>b[i];
    for (int i=0;i<10;i++){
        if(a[i]>b[i]){
            as=as+3;
            d=1;
        }
        else if(a[i]<b[i]){
            bs=bs+3;
            d=2;
        }
        else {
            as=as+1;
            bs=bs+1;
        }
    }
    cout<<as<<" "<<bs<<endl;
    if(as>bs||as==bs&&d==1)
    cout<<"A"<<endl;
    else if(as<bs||as==bs&&d==2)
    cout<<"B"<<endl;
    else 
    cout<<"D"<<endl;
}