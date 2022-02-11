#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t, n, m, importance;
    cin >> t;

    while(t--) {
        cin >> n >> m;
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq; // 중요도에 따라 정렬되는 우선순위 큐
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++) { // (i : 문서 순서)
            cin >> importance;
            q.push({importance, i});
            pq.push({importance, i});
        }

        int order = 0;
        while(!pq.empty()) {
            if(pq.top().first == q.front().first) { // pop : 중요도 만족
                int pos = q.front().second;
                pq.pop(); q.pop(); order++;

                if(pos == m) { // pop한 문서가 m번째 문서인 경우
                    cout << order << '\n';
                    break;
                }
            }
            else { q.push(q.front()); q.pop(); } // push
        }
    }
    return 0;
}
