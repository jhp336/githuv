#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    vector <int> n;
    cin>>s;
    int sum=0,cnt=-1;
    for(int i=0;i<s.size();i++){
        int num=s[i]-48;
        n.push_back(num);
        sum=sum+num;
        if(n.at(i)==0)
        cnt=1;
        } 
    
    if(sum%3==0&&cnt==1){
    for(int i=0;i<n.size();i++){
        if(n.at(i)==0){
            int tmp=n.at(n.size()-1);
            n.at(n.size()-1)=0;
            n.at(i)=tmp;
            break;
        }
    }
    sort(n.begin(),n.end(),greater<int>());
    for(int i=0;i<n.size();i++)
    cout<<n.at(i);
    }
    else cout<<-1;
    return 0;
}