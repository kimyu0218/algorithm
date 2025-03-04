#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<vector<int>> neighbors, vector<int> spreaders) {
    int n = neighbors.size();

    vector<int> result(n, -1);
    vector<int> half_cnt(n, 0);
    queue<int> q;

    for(int i = 0; i < n; i++) {
        int n_cnt = neighbors[i].size();
        half_cnt[i] = (n_cnt / 2) + (n_cnt % 2);
    }

    for(int i = 0; i < spreaders.size(); i++) {
        int node = spreaders[i];
        q.push(node);
        result[node] = 0;
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i = 0; i < neighbors[node].size(); i++) {
            int next = neighbors[node][i];

            if(--half_cnt[next] > 0 || result[next] != -1) {
                continue;
            }
            q.push(next);
            result[next] = result[node] + 1;
        }
    }
    return result;
}

int main() {
    int n, m, num;
    vector<vector<int>> neighbors;
    vector<int> spreaders;

    cin >> n;

    neighbors.assign(n, vector<int>(0));
    for(int i = 0; i < n; i++) {
        while(true) {
            cin >> num;
            if(!num) {
                break;
            }
            neighbors[i].push_back(num - 1);
        }
    }

    cin >> m;

    spreaders.assign(m, 0);
    for(int i = 0; i < m; i++) {
        cin >> num;
        spreaders[i] = num - 1;
    }

    vector<int> t = solution(neighbors, spreaders);

    for(int i = 0; i < n; i++) {
        cout << t[i] << ' ';
    }
    return 0;
}