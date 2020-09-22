#include <iostream>
#include<set>
using namespace std;
int cnt=0;
void cal(multiset<int>s1,multiset<int>s2,int m){
    multiset<int>::iterator it;
        multiset<int>::iterator itt;
        for(it=--s1.end();it!=s1.begin();){
            cnt=cnt+2*(*it);
            for(int i=0;i<m;i++){
                it--;
                if(i==0)
                itt=it;
                if(it==s1.begin()){
                    break;
                }
            }
        }
        cnt=cnt+2*(*itt);
        
        
        for(it=--s2.end();it!=s2.begin();){
            if(it!=--s2.end())
            cnt=cnt+2*(*it);
            else cnt=cnt+*it;
            for(int i=0;i<m;i++){
               it--;
                if(i==0)
                itt=it;
                if(it==s1.begin()){
                    break;
                }
            }
        }
        cnt=cnt+2*(*itt);
}
int main() {
    int n,m;
    cin>>n>>m;
    multiset<int> s1,s2;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(tmp>0)
        s1.insert(tmp);
        else s2.insert(tmp*(-1));
    }
    int h1=*--s1.end();
    int h2=*--s2.end();
    multiset<int>::iterator it;
        multiset<int>::iterator itt;
        int ch=0;
        for(it=--s1.end();it!=s1.begin();){
            cnt=cnt+2*(*it);
            for(int i=0;i<m;i++){
                it--;
                if(i==0)
                itt=it;
                if(it==s1.begin()){
                    ch=1;
                    break;
                }
            }
        }
        
        
        ch=0;
        for(it=--s2.end();it!=s2.begin();){
            if(it!=--s2.end())
            cnt=cnt+2*(*it);
            else cnt=cnt+*it;
            for(int i=0;i<m;i++){
               it--;
                if(i==0)
                itt=it;
                if(it==s1.begin()){
                    ch=1;
                    break;
                }
            }
        }
        
    

    cout<<cnt;
    return 0;

}