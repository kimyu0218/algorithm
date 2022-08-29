#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, a, b, q, t, k;
    cin >> n;

    graph.assign(n+1, vector<int> (0));
    for(int i = 0; i < n-1; i++) { // 간선 정보 입력
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cin >> q;
    while(q--) {
        cin >> t >> k;
        // 1. 연결된 간선이 2개 이상이면 해당 정점이 없어도 그래프가 2개 이상 존재함
        if(t == 1) cout << ((graph[k].size() >= 2) ? "yes\n" : "no\n");
        // 2. 모든 간선은 단절선
        else if(t == 2) cout << "yes\n";
    }
    return 0;
}