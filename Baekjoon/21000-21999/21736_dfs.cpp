#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> pi;

const char WALL = 'X';
const char VISITED = 'V';
const char DOYEON = 'I';
const char PERSON = 'P';
const string TT = "TT";

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

pi find_doyeon(int n, int m, vector<vector<char>> campus) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(campus[i][j] == DOYEON) {
                return { i, j };
            }
        }
    }
    return { -1, -1 };
}

string solution(vector<vector<char>> campus) {
    int result = 0;
    int n = campus.size();
    int m = campus[0].size();
    stack<pi> s;
    
    pi doyeon = find_doyeon(n, m, campus);
    campus[doyeon.first][doyeon.second] = VISITED;
    s.push(doyeon);
    
    while(!s.empty()) {
        int r = s.top().first;
        int c = s.top().second;
        s.pop();
        
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || campus[nr][nc] == VISITED || campus[nr][nc] == WALL) {
                continue;
            }
            result += (campus[nr][nc] == PERSON);
            campus[nr][nc] = VISITED;
            s.push({nr, nc});
        }
    }
    return result ? to_string(result) : TT;
}

int main() {
    int n, m;
    string input;
    vector<vector<char>> campus;
    
    cin >> n >> m;
    
    campus.assign(n, vector<char> (m, '\0'));
    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 0; j < m; j++) {
            campus[i][j] = input[j];
        }
    }
    
    cout << solution(campus);
    return 0;
}