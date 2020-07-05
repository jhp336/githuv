#include <iostream>
#include <string>
using namespace std;

int main() {
    string w;
    int now=0;
    getline(cin,w);
   
    for(int i=0;i<w.length();i++){
        if(w.at(i)==' ')
        now++;
    }
    if(w.at(0)==' ')
    now--;
    if(w.at(w.length()-1)==' ')
    now--;
    cout<<now+1<<endl;
    
    return 0;

}