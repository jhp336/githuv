#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
    string ch,s="     ",ss="     ";
    int xnum,ans,cnt=1; 
    int xn[xnum];
    cin>>ch;
    cin>>xnum;
    for(int i=0;i<xnum;i++)
    cin>>xn[i];
    if(xnum)
    for(int i=0;i<ch.size();i++){
        for(int j=0;j<xnum;j++){
            if(ch[i]==xn[j]){
                double tmp=ch[i]-48;
                while(tmp>1){
                    for (int k=0;k<xnum;k++){
                        if(tmp-1==xn[k]){
                            cnt=0;
                            break;
                        }
                    }
                    if(cnt==0)
                    tmp=tmp-1;
                    else{
                        s[i]=tmp-1+48;
                        for(int m=i+1;m<ch.size();m++){
                            for(int n=9;n>=0;n--){
                                for(int o=0;o<xnum;o++){
                                    if(n!=xn[o])
                                    s[m]=(char)n+48;
                                }
                            }
                        }
                    break;
                    }
                    if(cnt==0&&tmp==1)
                    s="-500000";
                }
                tmp=ch[i]-48;
                cnt=1;
                if(tmp==9){
                    string sss="10";
                    for (int k=0;k<xnum;k++){
                        if(i!=0){   
                            while(ss[i-1]<=8+48){
                                for(int n=0;n<xnum;n++){
                                    if(ss[i-1]+1==xn[n]){
                                        cnt=0;
                                        break;
                                    }
                                }
                                if(cnt==0)
                                ss[i-1]=ss[i-1]+1;
                                else {
                                    for(int m=i;m<ch.size();m++){
                                        for(int n=0;n<10;n++){
                                            for(int o=0;o<xnum;o++){
                                                if(n!=xn[o])
                                                ss[m]=n+48;
                                            }
                                        }
                                    }
                                    break;
                                }
                                if(cnt==0&&ss[i-1]==9+48)
                                ss="500000";
                            }                                
                        }
                        else {
                            ss[0]='1';
                            ss[1]='0';
                            while(ss[0]<=8+48){
                                for(int n=0;n<xnum;n++){
                                    if(ss[i-1]+1==xn[n]){
                                        cnt=0;
                                        break;
                                    }
                                }
                                if(cnt==0)
                                ss[i-1]=ss[i-1]+1;
                                else {
                                    for(int m=i;m<ch.size();m++){
                                        for(int n=0;n<10;n++){
                                            for(int o=0;o<xnum;o++){
                                                if(n!=xn[o])
                                                ss[m]=n+48;
                                            }
                                        }
                                    }
                                    break;
                                }
                                if(cnt==0&&ss[i-1]==9+48)
                                ss="500000";
                            } 
                        }
                    }
                }
                cnt=1;
                while(tmp<9){
                    for (int k=0;k<xnum;k++){
                        if(tmp+1==xn[k]){
                            cnt=0;
                            break;
                        }
                    }
                    if(cnt==0)
                    tmp=tmp+1;
                    else{
                        ss[i]=tmp+1+48;
                        for(int m=i+1;m<ch.size();m++){
                            for(int n=0;n<=9;n++){
                                for(int o=0;o<xnum;o++){
                                    if(n!=xn[o])
                                    ss[m]=(char)n+48;
                                }
                            }
                        }
                        break;
                    }
                    if(cnt==0&&tmp==9)
                    ss="500000";
                }
            }
            else {
                s[i]=ch[i];
                ss[i]=ch[i];
            }
        }
    }
    if(s.size()+stoi(ch)-stoi(s)<=ss.size()+stoi(ss)-stoi(ch))
    ans=s.size()+stoi(ch)-stoi(s);
    else ans=ss.size()+stoi(ss)-stoi(ch);
    if(100-stoi(ch)<ans||stoi(ch)-100<ans){
        if (100-stoi(ch)<0)
        ans=stoi(ch)-100;
        else ans=100-stoi(ch);
    }
    cout<<ans;
}