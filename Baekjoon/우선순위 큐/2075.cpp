#include <iostream>
#include <queue>

using namespace std;

typedef priority_queue<int, vector<int>, greater<>> pq;

pq init_priority_queue(int n, vector<int> &v) {
    pq result;
    for(int i = 0; i < n; i++) {
        result.push(v[i]);
    }
    return result;
}

int solution(int n, vector<vector<int>> &v) {
    pq big_n = init_priority_queue(n, v[0]);

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] <= big_n.top()) {
                continue;
            }
            big_n.pop();
            big_n.push(v[i][j]);
        }
    }
    return big_n.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<vector<int>> v;

    cin >> n;

    v.assign(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    cout << solution(n, v);
    return 0;
}