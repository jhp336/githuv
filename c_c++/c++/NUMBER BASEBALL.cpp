#include <iostream>
#include <time.h>
#include <set>
using namespace std;
int main() {
    while (1){
        cout<<"몇 자리로 할까요??(-1 입력 시 게임 종료!!)\n";
        int n;
        cin>>n;
        if(n==-1){
            cout<<"게임 종료!!\n";
            break;
        }
        srand(time(NULL));
        string s;
        int ans[n],ss[n];
        for(int i=0;i<n;i++){
            set<int>s;
            int x=rand()%10;
            if(s.find(x)!=s.end())
            i--;
            else {
                ans[i]=x;
                s.insert(x);
            }
        }
        while(1){            
            int str=0,ball=0;
            cout<<n<<" 자리 숫자를 입력해 주세요:(첫 자리 0 가능, -1 입력 시 게임 종료!)\n";
            cin>>s;
            for(int i=0;i<n;i++)
            ss[i]=s[i]-48;
            if(s=="-1"){
                cout<<"게임 종료!!\n\n";
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
                cout<<"정답입니다!!ㅋ\n\n";
                break;
            }
            else
            cout<<str<<" 스트라이크, "<<ball<<" 볼 입니다!\n\n";
        }
    }
    return 0;
}