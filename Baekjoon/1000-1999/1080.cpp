#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;

bool is_same_matrix(int n, int m, vector<vector<int>> a, vector<vector<int>> b) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void flip(int sr, int sc, vector<vector<int>> &a) {
    for(int i = sr; i < sr + SIZE; i++) {
        for(int j = sc; j < sc + SIZE; j++) {
            a[i][j] = !a[i][j];
        }
    }
}

int solution(vector<vector<int>> a, vector<vector<int>> b) {
    int result = 0;
    int n = a.size();
    int m = a[0].size();

    for(int i = 0; i <= n - SIZE; i++) {
        for(int j = 0; j <= m - SIZE; j++) {
            if(a[i][j] == b[i][j]) {
                continue;
            }
            flip(i, j, a);
            result++;
        }
    }
    return is_same_matrix(n, m, a, b) ? result : -1;
}

int main() {
    int n, m;
    vector<vector<int>> a;
    vector<vector<int>> b;
    string input;

    cin >> n >> m;

    a.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 0; j < m; j++) {
            a[i][j] = input[j] - '0';
        }
    }

    b.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 0; j < m; j++) {
            b[i][j] = input[j] - '0';
        }
    }

    cout << solution(a, b);
    return 0;
}