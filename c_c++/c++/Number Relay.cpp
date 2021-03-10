#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long cnt=0;
    if(n<10)
    cnt=n;
    else {
        cnt=9;
        if(n<100)
        cnt=cnt+(n-9)*2;
        else{
            cnt=cnt+90*2;
            if(n<1000)
            cnt=cnt+(n-99)*3;
            else{
                cnt=cnt+900*3;
                if(n<10000)
                cnt=cnt+(n-999)*4;
                else{
                    cnt=cnt+9000*4;
                    if(n<100000)
                    cnt=cnt+(n-9999)*5;
                    else{
                        cnt=cnt+90000*5;
                        if(n<1000000)
                        cnt=cnt+(n-99999)*6;
                        else{
                            cnt=cnt+900000*6;
                            if(n<10000000)
                            cnt=cnt+(n-999999)*7;
                            else{
                                cnt=cnt+9000000*7;
                                if(n<100000000)
                                cnt=cnt+(n-9999999)*8;
                                else cnt=cnt+90000000*8+9;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}