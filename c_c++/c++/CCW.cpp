#include <iostream>
#include <vector>
using namespace std;
int kc(int a,int b){
    if(a<b)
    return 1;
    else if(a>b)
    return -1;
    else return 0;
}
int main() {
    vector <pair<int,int>> v(3);        
    double k[2];
    for(int i=0;i<3;i++){
        cin>>v[i].first>>v[i].second;
    }
    for(int i=0;i<2;i++){
        if((v[i].first==v[i+1].first)&&(v[i].second==v[i+1].second)){
            cout<<"0";
            return 0;
        }
        if(v[i].first==v[i+1].first){
            if(i==0){
                if(v[2].first>v[1].first)
                cout<<"-1";
                else if(v[2].first<v[1].first)
                cout<<"1";
                else cout<<"0";
                return 0;
            }
            else if(i==1){
                if(v[0].first<v[1].first){
                    if(v[1].second<v[2].second)
                    cout<<"1";
                    else if(v[1].second>v[2].second)
                    cout<<"-1";
                }
                else if(v[0].first>v[1].first){
                    if(v[1].second<v[2].second)
                    cout<<"-1";
                    else if(v[1].second>v[2].second)
                    cout<<"1";
                }
                return 0;
            }
        }
        
        k[i]=(double)(v[i+1].second-v[i].second)/(v[i+1].first-v[i].first);
        
    }
    if(k[0]==k[1]){
        cout<<"0";
        return 0;
    }
    int cnt=kc(k[0],k[1])*kc(v[1].first,v[2].first);
    if(k[1]!=0){
        if(v[0].first<v[1].first){
            if(cnt==1)
            cout<<"1";
            else if(cnt==-1)
            cout<<"-1";
            return 0;
        }
        else if(v[0].first<v[1].first){
            if(cnt==1)
            cout<<"-1";
            else if(cnt==-1)
            cout<<"1";
            return 0;
        }
    }
    if(k[1]==0&&(v[2].first<v[1].first)){
        int cnt2=kc(0,k[0])*kc(v[0].first,v[1].first);
        if(cnt2==1)
        cout<<"1";
        else cout<<"-1";
    }
    else if(k[1]==0&&(v[2].first>v[1].first)){
        int cnt2=kc(0,k[0])*kc(v[0].first,v[1].first);
        if(cnt2==1)
        cout<<"-1";
        else cout<<"1";
    }
    return 0;
}