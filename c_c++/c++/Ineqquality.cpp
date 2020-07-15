#include <iostream>
#include <vector>
using namespace std;
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int main() {
    int n;
    cin>>n;
    vector <char> ieq(n);
    for(int i=0;i<n;i++){
        cin>>ieq[i];
    }
    vector <int> max(n+1);
    vector <int> min(n+1);
    for (int i=0;i<n+1;i++){
        min[i]=i;
        max[i]=9-i;
    }
    for(int h=0;h<n;h++){
        for(int i=0;i<n;i++){
            if(ieq[i]=='>'){
                if (min[i]<min[i+1])
                swap(&min[i],&min[i+1]);
                if (max[i]<max[i+1])
                swap(&max[i],&max[i+1]);
            }
            if(ieq[i]=='<'){
                if (min[i]>min[i+1])
                swap(&min[i],&min[i+1]);
                if (max[i]>max[i+1])
                swap(&max[i],&max[i+1]);
            }
        }
    }
    for (int i=0;i<n+1;i++)
    cout<<max[i];
    cout<<'\n';
    for (int i=0;i<n+1;i++)
    cout<<min[i];
    return 0;
}