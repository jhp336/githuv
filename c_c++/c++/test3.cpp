#include <iostream>
#include <queue>

using namespace std;

void solution(int n) {
    priority_queue <int> pq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x != 0) {
            pq.push(x);
            continue;
        }
        if (pq.size() == 0) {
            cout << 0 << endl;
        } else {
            cout << pq.top() << endl;
            pq.pop();
        }
    }
}

int main() {
    int n;
    cin >> n;

    solution(n);
}