#include <iostream>
using namespace std;
int c(int& a,int& b){
   return a+b;
}
int main() {
    int a=4,b=9;
    cout<<c(a,b);
    
}