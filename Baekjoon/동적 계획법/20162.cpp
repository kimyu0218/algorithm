#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> score) {
    int n = score.size();
    vector<int> dp (n + 1 ,0);
    
    for(int i = 0; i < n; i++) {
        dp[i] = score[i];
        for(int j = 0; j < i; j++) {
            if(score[i] <= score[j]) {
                continue;
            }
            dp[i] = max(dp[i], dp[j] + score[i]);
        }
        dp[n] = max(dp[n], dp[i]);
    }
    return dp[n];
}

int main() {
    int n;
    vector<int> score;
    
    cin >> n;
    
    score.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> score[i];
    }
    
    cout << solution(score);
    return 0;
}