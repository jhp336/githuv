#include <iostream>
#include  <vector>
#include <string>
#include <algorithm>
using namespace std;
struct acc{
    int age;
    string name;
};
bool cmp(const acc &a,const acc&b){
    return a.age<b.age;
}
int main() {
    int n;
    cin>>n;
    vector<acc>v(n);
    
    for(int i=0;i<n;i++){
        cin>>v[i].age>>v[i].name;
    }
   stable_sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
    cout<<v[i].age<<' '<<v[i].name<<endl;
    
    return 0;
}