#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> a, b;

int multiply(vector<int> v1, vector<int> v2, int m) {
    int result = 0;
    for(int i = 0; i < m; i++) result += (v1[i] * v2[i]);
    return result;
}

int main() {
    int n, m, k;

    cin >> n >> m;
    a.assign(n, vector<int> (m, 0)); // n x m 행렬
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    cin >> m >> k;
    b.assign(k, vector<int> (m, 0)); // m x k 행렬 뒤집어서 저장 -> k x m 행렬
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++)
            cin >> b[j][i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++)
            cout << multiply(a[i], b[j], m) << ' ';
        cout << '\n';
    }
    return 0;
}