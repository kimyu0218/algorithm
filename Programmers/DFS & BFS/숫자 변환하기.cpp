#include <string>
#include <vector>

using namespace std;

const int MAX = 1e6;
vector<int> dp; // dp[i] : x에서 i를 만드는데 필요한 최소 연산 수

void dfs(int x, int y, int cnt, int n) {
    dp[x] = cnt;
    if(x == y) { // x -> y 변환 성공
        return;
    }

    // case 1
    if(y >= x+n && dp[x+n] > cnt+1) {
        dfs(x+n, y, cnt+1, n);
    }
    // case 2
    if(y >= x*2 && dp[x*2] > cnt+1) {
        dfs(x*2, y, cnt+1, n);
    }
    // case 3
    if(y >= x*3 && dp[x*3] > cnt+1) {
        dfs(x*3, y, cnt+1, n);
    }
}

int solution(int x, int y, int n) {
    dp.assign(MAX+1, MAX+1);
    dfs(x, y, 0, n);
    if(dp[y] == MAX+1) { // x -> y 변환 불가
        return -1;
    }
    return dp[y];
}