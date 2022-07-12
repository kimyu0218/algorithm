#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator() (int a, int b) {
        return a < b; // 오름차순
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, x;
    priority_queue<int, vector<int>, cmp> pq; // cmp에 의해 top에 가장 큰 수가 위치함

    cin >> n;
    while(n--) {
        cin >> x;
        if(x == 0) { // 1. pop 연산
            if(pq.empty()) { // 1-1. 배열이 비어있는 경우
                cout << 0 << '\n';
            }
            else { // 1-2. 배열에서 가장 큰 값 출력 후 pop
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(x); // 2. push 연산
    }
    return 0;
}