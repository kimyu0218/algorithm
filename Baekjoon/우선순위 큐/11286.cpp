#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator() (int a, int b) {
        if(abs(a) != abs(b)) return abs(a) > abs(b); // 1. 절대값이 가장 작은 수
        return a > b; // 2. 가장 작은 수
    }
};

int main() {
    int n, x;
    cin >> n;

    priority_queue<int, vector<int>, cmp> pq;
    while(n--) {
        cin >> x;
        if(x == 0) {
            if(pq.empty()) { // 배열이 비어있는 경우
                cout << 0 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(x);
    }
    return 0;
}