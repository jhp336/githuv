#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    double m;
    cin>>n>>m;
    int card[n];
    for (int i=0;i<n;i++)
    cin>>card[i];
    int sumof3,i,j,k;
    vector <int> a(n*n*n);
    a.clear();
    for(i=0;i<n;i++)
        for (j=i+1;j<n;j++){
            for (k=j+1;k<n;k++){
                sumof3=card[i]+card[j]+card[k];
                if(sumof3<=m)
                a.push_back(sumof3);
            }
    }
    double max;
    max=a.at(0);
    for(i=0;i<a.size();i++){
        if(a.at(i)>max)
        max=a.at(i);
    }
    cout<<max;
    return 0;
}


