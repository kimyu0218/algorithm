#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1e4;
int n;
vector<int> computer[MAX+1];

int bfs(int start) {
    int cnt = 1; // (해킹 시작하는 컴퓨터 포함)
    vector<bool> hacked(n+1, false);

    queue<int> q;
    q.push(start); hacked[start] = true; // 해킹 완료

    while(!q.empty()) {
        int c1 = q.front(); q.pop();

        for(int i = 0; i < computer[c1].size(); i++) {
            int c2 = computer[c1][i];
            if(hacked[c2]) continue; // 이미 해킹한 컴퓨터 pass
            // 해킹
            hacked[c2] = true;
            cnt++;
            q.push(c2);
        }
    }
    return cnt;
}

vector<int> hack() {
    int max = 0;
    vector<int> answer;
    for(int i = 1; i <= n; i++) {
        int cnt = bfs(i);
        if(cnt > max) {
            answer = {i};
            max = cnt;
        }
        else if(cnt == max) {
            answer.push_back(i);
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m, a, b;
    cin >> n >> m;

    while(m--) {
        cin >> a >> b;
        computer[b].push_back(a);
    }

    vector<int> answer = hack();
    for(int i = 0; i < answer.size(); i++) { // 정답 출력
        cout << answer[i] << ' ';
    }
    return 0;
}