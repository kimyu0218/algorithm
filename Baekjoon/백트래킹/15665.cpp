#include <iostream>
#include <set>

using namespace std;

const int MAX = 7;

int result[MAX];
set<int> s;

void solution(int idx, int n, int m) {
    if(idx == m) {
        for(int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(auto iter = s.begin(); iter != s.end(); iter++) {
        result[idx] = *iter;
        solution(idx + 1, n, m);
    }
}

int main() {
    int n, m, num;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num;
        s.insert(num);
    }

    solution(0, n, m);
    return 0;
}