#include <iostream>
#include<set>
using namespace std;
int cnt=0;
void cal1(multiset<int>s1,int m){
    multiset<int>::iterator it;
        for(it=--s1.end();it!=s1.begin();){
            for(int i=0;i<m;i++){
                if(i==0)
                cnt=cnt+2*(*it);
                it--;
                if(it==s1.begin()){
                    if(i==m-1)
                    cnt=cnt+2*(*it);
                    break;
                }  
            }
        }   
    if(s1.size()==1)
    cnt=cnt+2*(*it);     
        
}
void cal2(multiset<int>s2,int m){
    multiset<int>::iterator it;
    for(it=--s2.end();it!=s2.begin();){
            for(int i=0;i<m;i++){
                if(i==0){
                    if(it!=--s2.end())
                    cnt=cnt+2*(*it);
                    else cnt=cnt+(*it);
                }
                it--;
                if(it==s2.begin()){
                    if(i==m-1)
                    cnt=cnt+2*(*it);
                    break;
                }  
            }
    }
    if(s2.size()==1)
    cnt=cnt+(*it);
}
int main() {
    int n,m,h1,h2;
    cin>>n>>m;
    multiset<int> s1,s2;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(tmp>0)
        s1.insert(tmp);
        else s2.insert(tmp*(-1));
    }
    if(!s1.empty())
    h1=*--s1.end();
    else h1=0;
    if(!s2.empty())
    h2=*--s2.end();
    else h2=0;
    if(h1<h2){
        if(h1)
        cal1(s1,m);
        cal2(s2,m);
    }
    else {
        if(h2)
        cal1(s2,m);
        cal2(s1,m);
    }
    cout<<cnt;
    return 0;

}