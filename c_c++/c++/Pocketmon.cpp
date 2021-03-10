#include <iostream>
#include <map>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    string arr1[n];
    map<string,int> arr2;
    map<string,int>::iterator it;
    string qst[m];
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        arr1[i]=s;
        arr2[s]=i+1;
    }
    for(int i=0;i<m;i++){
        cin>>qst[i];
    }
    for(int i=0;i<m;i++){
        if(atoi(qst[i].c_str())){
            int q=stoi(qst[i]);
            cout<<arr1[q-1]<<'\n';
        }
        else{
            it=arr2.find(qst[i]);
            cout<<it->second<<'\n';
        }
    }
    return 0;
}