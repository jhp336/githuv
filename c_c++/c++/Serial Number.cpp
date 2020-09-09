#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cal(string a){
    int cnt=0;
    for(int i=0;i<a.length();i++){
        char c[1]{a[i]};
        if(atoi(c)!=0)
        cnt=cnt+atoi(c);
    }
    return cnt;
}
bool cmp(string a,string b){
    int acnt=a.length();
    int bcnt=b.length();
    if(acnt!=bcnt)
    return acnt<bcnt;
    acnt=cal(a);
    bcnt=cal(b);
    if(acnt!=bcnt)
    return acnt<bcnt;
    return a<b; 
}
int main() {
    int n;
    cin>>n;
    vector<string> arr;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }
    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<'\n';
    }
    return 0;
}