#include <iostream>
#include <time.h>
#include <set>
using namespace std;
int main() {
    while (1){
        cout<<"How many numbers?(Press -1 if you want to exit!)\n";
        int n;
        cin>>n;
        if(n==-1){
            cout<<"Game Over!!\n";
            break;
        }
        srand(time(NULL));
        string s;
        int ans[n],ss[n];
        set<int>set{0};
        for(int i=0;i<n;i++){
            int x=rand()%10;
            if(set.find(x)!=set.end())
            i--;
            else {
                ans[i]=x;
                set.insert(x);
            }
        }
        while(1){            
            int str=0,ball=0;
            cout<<"Press "<<n<<" numbers plz:(0 can enter in first place, press -1 if you want to stop!)\n";
            cin>>s;
            for(int i=0;i<n;i++)
            ss[i]=s[i]-48;
            if(s=="-1"){
                cout<<"Answer is ";
                for(int i=0;i<n;i++)
                cout<<ans[i];
                cout<<"\nYOU LOSED BRO\n\n";
                break;
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(ss[i]==ans[j]){
                        if(i==j)
                        str++;
                        else ball++;
                        break;
                    }
                }
            }
            if(str==n){
                cout<<"YOU CORRECT!!\n\n";
                break;
            }
            else
            cout<<str<<" STRIKE, "<<ball<<" BALL!\n\n";
        }
    }
    return 0;
}