#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int num[9]={ };
    for (int i=0;i<9;i++)
    cin>>num[i];
    int num2[9]={ };
    copy(num,num+9,num2);
    int no,max;
    max=num[0];
    for(int i=0;i<9;i++){
        if (max<num[i]){
        max=num[i];
        no=i+1;
        }
        
    }
    
    
    cout<<max<<endl<<no<<endl;
    
    return 0;
}
