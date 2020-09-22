#include <iostream>
using namespace std;
int main() {
    int n,m,cnt=0;
    cin>>n>>m;
    int ssg=n,remain=0;
    for(int i=0;i<n;i++){
        int man=m;
        while(man>ssg){
            man=man-ssg;
            cnt++;
        }
        remain=remain+man;
        while(remain>=ssg){
            remain=remain-ssg;
            if(remain!=0)
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}