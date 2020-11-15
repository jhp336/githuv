//학번, 이름 추가 
#include "sets.h"
#include <algorithm>
using namespace std;

Sets::Sets(int numberOfElements)  // constructor
{
	if (numberOfElements < 2) throw "Must have at least 2 elements";
	n = numberOfElements;
	parent = new int[n];
	fill(parent, parent + n, -1);
}

ostream& operator<<(ostream& os, Sets&s)
{   
	//parent[i] 값을 출력하기 
        //for (int i = ...
    for(int i=0;i<s.n;i++){
        os<<i<<':'<<s.parent[i]<<"  ";
    }
    os<<"\n";
	return os;
}
void Sets::SimpleUnion(int i, int j)
{
	// 교재 참조 작성
    parent[i]=j;
}

int Sets::SimpleFind(int i)
{
	// 교재 참조 작성
    while(parent[i]>=0) i=parent[i];
    return i;
}

void Sets::WeightedUnion(int i, int j)
{
  	// 교재참조 작성
    int temp = parent[i]+parent[j];
	if(parent[i]>parent[j]){
		parent[i]=j;
		parent[j]=temp;
	}
	else{
		parent[j]=i;
		parent[i]=temp;
	}
}
