#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
const int MAX = 1e5;

pi cntCase(int n, int k) {
    vector<int> time (MAX+1, MAX+1);
    vector<int> cases(MAX+1, 0);
    queue<int> q;

    // 시작점 세팅
    time[n] = 0; // n 위치까지 이동하는 시간은 0
    cases[n] = 1; // n 위치까지 가장 빠른 시간으로 찾는 방법의 수
    q.push(n);

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        if(x == k) {
            continue;
        }

        // 1. 걷기
        if(x-1 >= 0 && time[x-1] >= time[x]+1) { // 1-1. x-1 이동
            if(time[x-1] == MAX+1) {
                q.push(x-1);
            }
            time[x-1] = time[x]+1;
            cases[x-1] += cases[x];
        }
        if(x+1 <= MAX && time[x+1] >= time[x]+1) { // 1-2. x+1 이동
            if(time[x+1] == MAX+1) {
                q.push(x+1);
            }
            time[x+1] = time[x]+1;
            cases[x+1] += cases[x];
        }
        // 2. 순간이동
        if(2*x <= MAX && time[2*x] >= time[x]+1) {
            if(time[2*x] == MAX+1) {
                q.push(2*x);
            }
            time[2*x] = time[x]+1;
            cases[2*x] += cases[x];
        }
    }
    return {time[k], cases[k]};
}

int main() {
    int n, k;
    cin >> n >> k;
    pi answer = cntCase(n, k);
    cout << answer.first << '\n' << answer.second;
    return 0;
}