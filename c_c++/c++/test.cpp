#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int tmp = a;
    a=b;
    b=tmp;
}
int main(){
    int a=3, b=7;
    cout<<a<<' '<<b<<'\n';
    swap(a,b);
    cout<<a<<' '<<b<<'\n';
}