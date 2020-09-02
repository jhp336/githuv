#include <iostream>
using namespace std;
int main () {
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.length();i++){
        char tmp,tmp2;
        if(i==0)
        tmp=s[0];
        else tmp=s[i-1];
        if(i==s.length()-1)
        tmp2=s[i];
        else tmp2=s[i+1];
        if(tmp=='c'&&(s[i]=='='||s[i]=='-')){
            cnt--;
        }
        else if(tmp=='d'&&((s[i]=='z'&&tmp2=='=')||s[i]=='-')){
            cnt--;
        }
        else if((tmp=='l'||tmp=='n')&&s[i]=='j'){
            cnt--;
        }
        else if((tmp=='s'||tmp=='z')&&s[i]=='='){
            cnt--;
        }
        cnt++;
    }
    cout<<cnt;
    return 0;
}