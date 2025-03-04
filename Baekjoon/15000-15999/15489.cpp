#include <iostream>
#include <vector>

using namespace std;

const int W = 29;

int dp[W + 1][W + 1];

void set_pascal_triangle() {
    for(int i = 1; i <= W; i++) {
        dp[i][1] = dp[i][i] = 1;
    }
    for(int i = 2; i <= W; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
}

int solution(int r, int c, int w) {
    int result = 0;
    
    set_pascal_triangle();
    
    for(int i = 0; i < w; i++) {
        for(int j = 0; j <= i; j++) {
            result += dp[i + r][j + c];
        }
    }
    return result;
}

int main() {
    int r, c, w;
    
    cin >> r >> c >> w;
    
    cout << solution(r, c, w);
    return 0;
}