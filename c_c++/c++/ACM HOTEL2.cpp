#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t,n,w,h;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>h>>w>>n;
        vector <int> a(w*h);
        a.clear();
        for(int k=0;k<w;k++)
        for(int j=0;j<h;j++){
            a.push_back((j+1)*100+k+1);
        }
    cout<<a.at(n-1)<<endl;
    }

}