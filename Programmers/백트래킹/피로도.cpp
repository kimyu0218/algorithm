#include <string>
#include <vector>

using namespace std;

const int MAX = 8;

bool visited[MAX];
int result = 0;

void backtracking(int cnt, int k, int n, vector<vector<int>> dungeons) {
    result = max(result, cnt);

    for(int i = 0; i < n; i++) {
        if(visited[i]) {
            continue;
        }
        if(k < dungeons[i][0] || k - dungeons[i][1] < 0) {
            continue;
        }
        visited[i] = true;
        backtracking(cnt + 1, k - dungeons[i][1], n, dungeons);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    backtracking(0, k, dungeons.size(), dungeons);
    return result;
}