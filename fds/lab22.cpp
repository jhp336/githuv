#include "rec.h"
#include <iostream>
using namespace std;
int main() {
    Rectangle r(2, 3, 4, 6), s(1, 2, 6, 6);

    cout << "<rectangle r> "; r.Print();
    cout << "<rectangle s> "; s.Print();
    if (r.LessThan(s))
    cout << "s is bigger";
    else if (r.Equal(s))
    cout << "Same Size";
    else cout << "r is bigger";
    cout << endl;
    if(r.Area()<s.Area())
    cout<<"S has greater area"<<endl;
    else if(r.Area()<s.Area())
    cout<<"R has greater area"<<endl;
    else cout<<"R and S have same area"<<endl;

    cout<<"<rectangle r> "<<r;
    cout << "<rectangle s> "<<s;
    if(r<s)
    cout<<"S is bigger"<<endl;
    else cout<<"R is bigger"<<endl;
    return 0;
}