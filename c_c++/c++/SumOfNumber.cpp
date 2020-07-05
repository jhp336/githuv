#include <iostream>
using namespace std;

int main () {
    int many;
    int sum=0;
    cin>>many;
    char num[100];
    cin>>num;
    for(int i=0;i<many;i++)
        sum=sum+num[i]-'0';
    cout<<sum;
    return 0;
}