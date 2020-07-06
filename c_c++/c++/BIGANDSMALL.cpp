#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int num[n];
    for (int i=0;i<n;i++)
    cin>>num[i];
    int max=num[0];
    int min=num[0];
    for(int i=0;i<n;i++){
    if(max<num[i])
    max=num[i];
    if(min>num[i])
    min=num[i];
    }
    cout<<min<<' '<<max<<endl;
    return 0;
}