#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e7;

vector<vector<int>> floyd_warshall(int n, vector<vector<int>> adj_matrix) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int new_w = adj_matrix[i][k] + adj_matrix[k][j];
                adj_matrix[i][j] = min(adj_matrix[i][j], new_w);
            }
        }
    }
    return adj_matrix;
}

vector<vector<int>> solution(vector<vector<int>> adj_matrix) {
    int n = adj_matrix.size();
    for(int i = 0; i < n; i++) {
        adj_matrix[i][i] = 0;
    }

    vector<vector<int>> result = floyd_warshall(n, adj_matrix);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(result[i][j] == INF) {
                result[i][j] = 0;
            }
        }
    }
    return result;
}

int main() {
    int n, m, a, b, c;
    vector<vector<int>> adj_matrix;

    cin >> n >> m;

    adj_matrix.assign(n, vector<int> (n, INF));
    while(m--) {
        cin >> a >> b >> c;
        adj_matrix[a - 1][b - 1] = min(adj_matrix[a - 1][b - 1], c);
    }

    vector<vector<int>> result = solution(adj_matrix);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}