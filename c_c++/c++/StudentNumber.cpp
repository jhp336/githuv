#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector <string> v;
    set<string>st;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    int leng = v.front().length();
    int i;
    for(i=leng-1;i>-1;i--){
        vector<string>::iterator it;
        st.clear();
        for(it=v.begin();it!=v.end();it++){
            string c="";
            for(int j=i;j<leng;j++)
            c=c+it->at(j);
            if(st.find(c)==st.end())
            st.insert(c);
            else break;
        }
        if (it==v.end())break;
    }
    cout<<leng-i;
}