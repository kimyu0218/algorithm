#include <iostream>
#include <vector>

using namespace std;

const int N = 200;
const int CNT = 3;

int result = 0;

int combi[CNT];
bool tasteless[N + 1][N + 1];

bool is_tasty() {
    return !tasteless[combi[0]][combi[1]] 
    && !tasteless[combi[0]][combi[2]]
    && !tasteless[combi[1]][combi[2]];
}

void backtracking(int cnt, int idx, int n) {
    if(cnt == CNT) {
        result += is_tasty();
        return;
    }
    
    for(int i = idx; i <= n; i++) {
        combi[cnt] = i;
        backtracking(cnt + 1, i + 1, n);
    }
}

int solution(int n) {
    backtracking(0, 1, n);
    
    return result;
}

int main() {
    int n, m, a, b;
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        tasteless[a][b] = tasteless[b][a] = true;
    }
    
    cout << solution(n);
    return 0;
}