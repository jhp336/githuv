#include <iostream>
#include <vector>
using namespace std;
int main() {
    int k,sum=0;
    cin>>k;
    vector <int> v;
    for(int i=0;i<k;i++){
        int a;
        cin>>a;
        if(a==0)
        v.pop_back();
        else v.push_back(a);
    }
    for(int i=0;i<v.size();i++)
    sum=sum+v[i];
    cout<<sum;

    return 0;
}