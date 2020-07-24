#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
    string ch;
    int xnum,ans; 
    int xn[xnum];
    cin>>ch;
    cin>>xnum;
    for(int i=0;i<xnum;i++)
    cin>>xn[i];
    ans=ch.size();
    int mul=pow(10,ch.size()-1);
    for(int i=0;i<ch.size();i++){
        for(int j=0;j<xnum;j++){
            if(ch[i]==xn[j]){
                double tmp=ch[i]-48;
                if(tmp==1)
                tmp==1.9;
                for (int k=0;k<xnum;k++){
                    if(tmp-1==xn[k]){
                        ans=(tmp+1)*mul-stoi(ch);
                        k=-1;
                    }


                if((tmp+1)*mul-stoi(ch)<stoi(ch)-(tmp-1)*mul)
                ans=(tmp+1)*mul-stoi(ch);
                }
            }
        }
    }
    if(100-stoi(ch)<ans||stoi(ch)-100<ans){
        if (100-stoi(ch)<0)
        ans=stoi(ch)-100;
        else ans=100-stoi(ch);
    }
}