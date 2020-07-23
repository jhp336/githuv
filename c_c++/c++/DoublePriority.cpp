#include <iostream>
#include <set>
using namespace std;
int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int k;
        cin>>k;
        multiset <int> n;
        double tmp;
        char c;
        for (int j=0;j<k;j++){
            cin>>c>>tmp;
            if (c=='I'){
                n.insert(tmp);
            }
            else if(c=='D'){
                if(!n.empty()){
                    auto end=n.end();
                    end--;
                    if (tmp==1)
                    n.erase(end);
                    else if(tmp==-1)
                    n.erase(n.begin());
                }
            }
        }
        if(n.empty())
        cout<<"EMPTY"<<'\n';
        else{
            auto end=n.end();
            end--;
            cout<<*end<<' '<<*n.begin()<<'\n';
        }
    }
    return 0;
}