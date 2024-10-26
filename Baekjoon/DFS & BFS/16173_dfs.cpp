#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct info {
    int r, c, cnt;
};

const int VISITED = -2;

int dr[2] = { 0, 1 };
int dc[2] = { 1, 0 };

string solution(vector<vector<int>> map) {
    int n = map.size();
    stack<info> s;
    
    s.push({0, 0, map[0][0]});
    map[0][0] = VISITED;
    
    while(!s.empty()) {
        int r = s.top().r;
        int c = s.top().c;
        int cnt = s.top().cnt;
        s.pop();
        
        for(int i = 0; i < 2; i++) {
            int nr = r + dr[i] * cnt;
            int nc = c + dc[i] * cnt;
            
            if(nr < 0 || nr >= n || nc < 0 || nc >= n || map[nr][nc] == VISITED) {
                continue;
            }
            s.push({nr, nc, map[nr][nc]});
            map[nr][nc] = VISITED;
        }
    }
    return map[n - 1][n - 1] == VISITED ? "HaruHaru" : "Hing";
}

int main() {
    int n;
    vector<vector<int>> map;
    
    cin >> n;
    
    map.assign(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    
    cout << solution(map);
    return 0;
}