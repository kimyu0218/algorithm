#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k, turn = 0;
    cin >> n >> k;

    vector<int> seq; // seq : 요세푸스 순열 저장하는 큐
    queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i);

    while(!q.empty()) {
        turn++;
        if(turn % k == 0) { // k번째 사람 제거
            seq.push_back(q.front());
            q.pop();
        }
        else { // 순환
            int front = q.front(); q.pop();
            q.push(front);
        }
    }

    // 결과 출력
    cout << '<';
    for(int i = 0; i < n-1; i++) cout << seq[i] << ", ";
    cout << seq[n-1] << '>';
    return 0;
}