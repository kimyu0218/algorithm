#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> s;

    int n = elements.size();
    vector<int> dp(n, 0);

    dp[0] = elements[0];
    for(int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + elements[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= n; j++) {
            int idx = (i + j) % n;
            if(idx > i) {
                int sum = dp[idx] - dp[i];
                s.insert(sum);
                continue;
            }
            int sum = dp[n - 1] - dp[i] + dp[idx];
            s.insert(sum);
        }
    }
    return s.size();
}