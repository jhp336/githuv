#include <iostream>
using namespace std;

int main() {
    int x,y,w,h;
    cin>>x>>y>>w>>h;
    int minx,miny;
    if(x<(double)w/2)
    minx=x;
    else minx=w-x;
    if(y<(double)h/2)
    miny=y;
    else miny=h-y;
    if(minx<miny)
    cout<<minx;
    else cout<<miny;
    return 0;
}