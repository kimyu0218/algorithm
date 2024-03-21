#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MINSIK = 0;

vector<vector<int>> make_tree(int n, vector<int> boss) {
    vector<vector<int>> result (n, vector<int>(0));
    for(int i = 1; i < n; i++) {
        result[boss[i]].push_back(i);
    }
    return result;
}

int dfs(int node, vector<vector<int>> tree) {
    if(tree[node].empty()) {
        return 1;
    }

    vector<int> leaves;
    for(int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i];
        leaves.push_back(dfs(next, tree) + 1);
    }
    sort(leaves.begin(), leaves.end(), greater<>());

    int result = 0;
    for(int i = 0; i < leaves.size(); i++) {
        result = max(result, leaves[i] + i);
    }
    return result;
}

int solution(vector<int> boss) {
    int n = boss.size();
    vector<vector<int>> tree = make_tree(n, boss);

    return dfs(MINSIK, tree) - 1;
}

int main() {
    int n;
    vector<int> boss;

    cin >> n;

    boss.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> boss[i];
    }

    cout << solution(boss);
    return 0;
}