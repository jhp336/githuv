#include <iostream>
using namespace std;
void move(int n,int fst,int sec,int thr){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(n==1){
        cout<<fst<<" "<<thr<<'\n';
    }
    else {
        move(n-1,fst,thr,sec);
        cout<<fst<<" "<<thr<<'\n';
        move(n-1,sec,fst,thr);
    }
}
int count(int n){
    int cnt=1;
    for(int i=1;i<n;i++){
        cnt=cnt*2+1;
    }
    return cnt;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int cnt=count(n);
    cout<<cnt<<'\n';
    move(n,1,2,3);
    return 0;
}
