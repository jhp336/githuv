#include <iostream>
#include <time.h>
#include <set>
using namespace std;
int main() {
    while (1){
        cout<<"�� �ڸ��� �ұ��??(-1 �Է� �� ���� ����!!)\n";
        int n;
        cin>>n;
        if(n==-1){
            cout<<"���� ����!!\n";
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
            cout<<n<<" �ڸ� ���ڸ� �Է��� �ּ���:(ù �ڸ� 0 ����, -1 �Է� �� ���� ����!)\n";
            cin>>s;
            for(int i=0;i<n;i++)
            ss[i]=s[i]-48;
            if(s=="-1"){
                cout<<"���� ����!!\n\n";
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
                cout<<"�����Դϴ�!!��\n\n";
                break;
            }
            else
            cout<<str<<" ��Ʈ����ũ, "<<ball<<" �� �Դϴ�!\n\n";
        }
    }
    return 0;
}