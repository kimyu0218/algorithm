#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int SIZE = 100;
const char SHEEP = '#';
const char VISITED = 'V';

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

char sheep[SIZE][SIZE];

void bfs(int sr, int sc, int h, int w) {
    queue<pi> q;
    
    sheep[sr][sc] = VISITED;
    q.push({sr, sc});
    
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr < 0 || nr >= h || nc < 0 || nc >= w || sheep[nr][nc] != SHEEP) {
                continue;
            }
            sheep[nr][nc] = VISITED;
            q.push({nr, nc});
        }
    }
}

int solution(int h, int w) {
    int result = 0;
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(sheep[i][j] == SHEEP) {
                result++;
                bfs(i, j, h, w);
            }
        }
    }
    return result;
}

int main() {
    int t, h, w;
    string input;
    
    cin >> t;
    while(t--) {
        cin >> h >> w;
        
        for(int i = 0; i < h; i++) {
            cin >> input;
            for(int j = 0; j < w; j++) {
                sheep[i][j] = input[j];
            }
        }
        
        cout << solution(h, w) << '\n';
    }
    return 0;
}