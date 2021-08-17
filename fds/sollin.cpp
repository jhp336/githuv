#include "mstree.h"

priority_queue< Edge, vector<Edge>, Compare >* PQ;

// 필요함수를 정의 및 구현하시오
void MovePQ(Sets sets, int r1, int r2) {
    if (r1 == sets.Find(r1)) {
        while (!PQ[r2].empty()) {
            PQ[r1].push(PQ[r2].top());
            PQ[r2].pop();
        }
    }
    else {
        while (!PQ[r1].empty()) {
            PQ[r2].push(PQ[r1].top());
            PQ[r1].pop();
        }
    }
}
void ReadEdges4sollin(istream& is) {
    PQ = new priority_queue<Edge, vector<Edge>, Compare>[NNODES];
    //각 점(tree) 마다 연결된 간선들의 minheap이 필요함. 
    // NNODES개의 minheap을 갖고 있는 PQ 배열을 생성하시오.  
   //PQ = new ....

    Edge e;

    while (GetEdge(is, e)) {
        PQ[e.v1].push(e);
        PQ[e.v2].push(e);
    }
}

void sollin() {
    Sets sets(NNODES);

    // 코드 추가 하기
    int nedges = 0;
    while (nedges < NNODES - 1) {
        for (int i = 0; i < NNODES; i++) {
            int tmp = sets.Find(i);
            if (PQ[tmp].empty()) throw "No Spanning Tree Exists.";
            Edge e;
            e = PQ[tmp].top(); PQ[tmp].pop();
            int r1 = sets.Find(e.v1);
            int r2 = sets.Find(e.v2);
            if (r1 != r2) {
                sets.WeightedUnion(r1, r2);
                MovePQ(sets, r1, r2);
                nedges++;
                cout << e;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    //파일 입력 부분은 kruskal경우와 동일하게
    //추가 
    ifstream is;
    if (argc == 1) is.open("kin.txt");
    else is.open(argv[1]);
    if (!is) { cerr << "No such input file\n"; exit(1); }
    is >> NNODES;
    if (NNODES < 2) { cerr << "#nodes must be 2.." << endl; exit(1); }
    try {
        ReadEdges4sollin(is);
        sollin();
    }
    catch (char const* str)
    {
        cerr << "Exception: " << str << endl; exit(1);
    }
}