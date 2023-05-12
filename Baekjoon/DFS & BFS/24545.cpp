#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int>> tree;
vector<map<int, int>> cnt_node; // 간선에 노드 수 저장

int dfs(int curr, int prev) {
    if (cnt_node[prev][curr]) {
        return cnt_node[prev][curr];
    }
    int cnt = 0;

    for (int next: tree[curr]) {
        if (next == prev) {
            continue;
        }
        cnt = max(cnt, dfs(next, curr));
    }
    return cnt_node[prev][curr] = cnt + 1;
}

int getMaxYTree(int n) {
    int ans = 0;

    // Y-트리의 중심이 될 노드를 순차적으로 탐색
    for (int curr = 1; curr <= n; curr++) {
        if (tree[curr].size() < 3) { // 간선의 수 < 3인 경우 중심이 될 수 없음
            continue;
        }
        vector<int> cnt; // 해당노드(curr)에서 나오는 간선에서 얻을 수 있는 노드의 수 저장

        for (int next: tree[curr]) {
            cnt.push_back(dfs(next, curr));
        }
        sort(cnt.begin(), cnt.end(), greater<>());
        ans = max(ans, cnt[0] + cnt[1] + cnt[2] + 1); // 가장 많은 노드를 선택할 수 있는 경우 세가지 + 중심점(curr)
    }

    return ans;
}

int main() {
    int n, u, w;

    cin >> n;
    tree.assign(n + 1, vector<int>(0));
    cnt_node.assign(n + 1, map<int, int>());

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> w;
        tree[u].push_back(w);
        tree[w].push_back(u);
    }

    cout << getMaxYTree(n);
    return 0;
}