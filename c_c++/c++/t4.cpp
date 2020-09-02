#include <iostream>
#include <deque>
using namespace std;
int main() {
    int n,m,cnt=0;
    n=10,m=3;
    deque<int> arr;
    deque<int>dq;
    for(int i=1;i<n+1;i++){
        dq.push_back(i);
    }
    for(int i=0;i<m;i++){
        int num[m]{2,9,5};
        arr.push_back(num[i]);
    }
    deque<int>::iterator it;
    for(int i=0;i<m;i++){
        while(dq.front()!=arr[i]){
            int ch=0;
            for(it=dq.begin();*it!=arr[i];it++){
                ch++;
            }
            if(ch<=dq.size()/2){
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            else{ 
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
        dq.pop_front();
        arr.pop_front();
    }
    cout<<cnt;
    return 0;
}