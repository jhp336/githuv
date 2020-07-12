#include <iostream>
#include <vector>
#include<string>
using namespace std;
int main() {
    int t=0,sum=0,cnt=0;
    vector <string> a(1);
    cin>>a.at(0);
    vector <string> s(50);
    for(int i=0;i<a.at(0).size();i++){
        if(a.at(0)[i]!='-'&&a.at(0)[i]!='+')
        s.at(cnt)=s.at(cnt)+a.at(0)[i];
        else {
        cnt++;
        s.at(cnt)=a.at(0)[i];
        cnt++;
        }
    }
    int pm;
    for(int i=0;i<s.size();i++){
        if(s.at(i)=="")
        break;
        if(s.at(i)=="-")
        pm=0;
        else if(s.at(i)=="+"){
        if(pm==0)
        pm=0;
        else pm=1;
        }
        else if(pm==0)
        sum=sum-stoi(s.at(i));
        else
        sum=sum+stoi(s.at(i));
        
    }
    cout<<sum;
    return 0;
}