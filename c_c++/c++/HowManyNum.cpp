#include <iostream>
using namespace std;
int main() {
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    double mul=a*b*c;
    int num[10]={0};
    char tmp[10]={0};
    sprintf(tmp,"%f",mul);
    for (int i=0;i<10;i++){
        if(tmp[i]==46)
        break;
        for(int j=0;j<10;j++){
            if(num[j]>9)
            num[j]=0;
            if (tmp[i]-48==j)
            num[j]++;
        }
    }
    for (int i=0;i<10;i++)
    cout<<num[i]<<'\n';
    return 0;
}