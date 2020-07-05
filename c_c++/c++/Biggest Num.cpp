#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int num[9]={ };
    for (int i=0;i<9;i++)
    cin>>num[i];
    int num2[9]={ };
    copy(num,num+9,num2);
    int no;

    for(int i=0;i<9;i++){
        for (int j=8;j>i;j--)
        if(num[i]>num[j]){
            int temp;
            temp=num[i];
            num[i]=num[j];
            num[j]=temp;
        }
    }
    for(int i=0;i<9;i++)
    if( num2[i]==num[8])
    no=i;
    
    cout<< num[8]<<endl<<no+1<<endl;
    
    return 0;
}
