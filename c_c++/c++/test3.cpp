#include <iostream>
using namespace std;
int main() {
    int t=1;

    for (int i=0;i<t;i++){
        int n,k;
        n=3,k=1;
    
        int h[k+1][n]{0};
        for(int j=0;j<n;j++){
            h[0][j]=j+1;
        }
        for(int j=1;j<k+1;j++){
             int sum=0;
            for(int l=0;l<n;l++){
                sum=sum+h[j-1][l];
                h[j][l]=sum;
            }
        } 
        cout<<h[k][n-1]<<'\n';
    }
    return 0;
}