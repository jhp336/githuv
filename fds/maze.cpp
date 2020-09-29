#include <iostream>
#include <stack>
using namespace std;

const int MAXSIZE=100; // up to 100 by 100 maze allowed

bool maze[MAXSIZE+2][MAXSIZE+2];
bool mark[MAXSIZE+1][MAXSIZE+1] = { 0 } ;

enum directions { N, NE, E, SE, S, SW, W, NW };

struct offsets
{
   int a, b;
} movea[8] = { -1,0,  -1,1,  0,1,  1,1,  1,0,  1,-1,  0,-1,  -1,-1 };

struct Items {
   Items(int xx=0, int yy=0, int dd=0): x(xx), y(yy), dir(dd) {}
   int x, y, dir;
};

template <class T>
ostream& operator<< (ostream& os, stack<T>& s) {
    //코드 입력:
    // 스택의 내용을 역순으로 출력
    // 구현방법=내용을 하나씩 꺼내 다른 임시 스택에 넣어 저장한 
    // 후, 최종적으로 그 임시 스택에서 하나씩 꺼내 출력하면 됨
    stack<T> temp;
    while(!s.empty()){
        temp.push(s.top());
        s.pop();
    }
    while(!temp.empty()){
        os<<" -> "<<temp.top();
        temp.pop();
    }
   return os;
}
ostream& operator<<(ostream& os, Items& item)
{
   static int count = 0; // 5개의 Items가 출력될 때마다 줄바꾸기위해
   os << "(" << item.x << "," << item.y << ")";
   count++; if ((count % 5) == 0) cout << endl;
   return os;
}
void Path(const int m, const int p)
{
  mark[1][1] = 1; 
  stack<Items> stack; // C++ STD stack을 이용하기
  Items temp(1, 1, E);
  stack.push(temp);
  //코드 입력
  /* 구현은 책과 동일하다. 단 최종적인 경로의 출력은 다음과 같이 한다.
    cout << stack;
    temp.x = i; temp.y = j; cout << " -> " << temp;
    temp.x = m; temp.y = p; cout << " -> " << temp << endl;
  */
 while(!stack.empty()){
    temp=stack.top();
    stack.pop();
    int i=temp.x; int j=temp.y; int d=temp.dir;
    while(d<8){
        int g=i+movea[d].a; int h=j+movea[d].b;
        if((g==m)&&(h==p)){
            cout << stack;
            temp.x = i; temp.y = j; cout << " -> " << temp;
            temp.x = m; temp.y = p; cout << " -> " << temp << endl;
            return;
        }
        if((!maze[g][h])&&(!mark[g][h])){
            mark[g][h]=1;
            temp.x=i; temp.y=j; temp.dir=d+1;
            stack.push(temp);
            i=g; j=h; d=N;
        }
        else d++;
    }
 }
 cout<<"No path in maze."<<endl;
}
void getdata(istream& is, int& m, int & p)
{ // 자료화일을 읽어들여 maze에 저장한다.
   is >> m >> p;
   for (int i = 0; i < m+2; i++) { maze[i][0] = 1; maze[i][p+1] = 1; }
   for (int j = 1; j <= p; j++) { maze[0][j] = 1; maze[m+1][j] = 1; }
   for (int i = 1; i <= m; i++)
      for (int j = 1; j <= p; j++)
         is >> maze[i][j];
}