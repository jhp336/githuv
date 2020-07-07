#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector <int> a;
    int b;
   
    for(int i=0;i<6;i++){
        cin>>b;
        a.push_back(b);
    }
    for(int i=0;i<6;i++)
    cout<<a.at(i);
    
}