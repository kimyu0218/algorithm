#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX = 8;
int num[MAX], arr[MAX];
set<vector<int>> s;

void backtracking(int idx, int cnt, int n, int m) {
    if(cnt == m) { // 기저 조건
        vector<int> tmp (m, 0);
        for(int i = 0; i < m; i++) {
            tmp[i] = arr[i];
        }
        if(s.find(tmp) == s.end()) { // 아직 한 번도 등장하지 않은 배열인 경우
            s.insert(tmp);
            for(int i = 0; i < m; i++) {
                cout << arr[i] << ' ';
            }
            cout << '\n';
        }
        return;
    }
    if(idx == n) { // 기저 조건
        return;
    }

    for(int i = idx; i < n; i++) {
        arr[cnt] = num[i];
        backtracking(i+1, cnt+1, n, m);
    }
}

int main() {
    int n, m;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n); // 오름차순 정렬
    backtracking(0, 0, n, m);
    return 0;
}