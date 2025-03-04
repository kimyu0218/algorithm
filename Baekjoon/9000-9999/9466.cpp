#include <iostream>
#include <vector>

using namespace std;

int n, cnt; // 학생 수, 팀을 이룬 학생 수
vector<bool> visited, done;
vector<int> s;

void dfs(int node) {
    visited[node] = true; // 방문 체크

    int next = s[node];
    if(!visited[next]) { // 1. 아직 방문하지 않은 정점인 경우, 깊게 탐색
        dfs(next); // (4 -> 7 -> 6 탐색 완료)
    }
    else if(!done[next]) { // 2. 이미 방문한 정점의 경우, 사이클에 포함된 학생 수 세기
        for(int i = next; i != node; i = s[i]) { // (4는 이미 방문한 정점이므로, 6에서 6으로 끝나는 사이클 확인 : 4 -> 7)
            cnt++;
        }
        cnt++; // node 포함 사이클 완성 (6까지 카운트)
    }
    done[node] = true; // 사이클 확인 완료
}

int notBelonging() { // 팀을 이루지 못하는 학생 수 반환
    cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    return n-cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) { // 테스트케이스
        cin >> n;
        s.assign(n+1, 0);
        visited.assign(n+1, false);
        done.assign(n+1, false);
        for(int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        cout << notBelonging() << '\n';
    }
    return 0;
}