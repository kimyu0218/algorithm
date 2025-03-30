#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> floyd_warshall(int n, vector<vector<int>> adj_matrix) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adj_matrix[i][k] && adj_matrix[k][j]) {
                    adj_matrix[i][j] = 1;
                }
            }
        }
    }
    return adj_matrix;
}

vector<vector<int>> solution(vector<vector<int>> adj_matrix) {
    return floyd_warshall(adj_matrix.size(), adj_matrix);
}

int main() {
    int n;
    vector<vector<int>> adj_matrix;

    cin >> n;

    adj_matrix.assign(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adj_matrix[i][j];
        }
    }

    vector<vector<int>> answer = solution(adj_matrix);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}