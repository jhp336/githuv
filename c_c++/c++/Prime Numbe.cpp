#include<iostream>
using namespace std;
int main() {
    int n,cnt=0;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
        int chk=0;
        for (int j=2;j<a[i];j++){
        if(a[i]%j==0){
            chk=0;
            break;
        }
        else chk=1;
        }
        if (a[i]==2)
        cnt++;
        if (chk==1){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}