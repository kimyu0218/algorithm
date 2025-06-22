#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    vector<int> dp (n, 0);
    set<int> s;

    dp[0] = elements[0];
    for(int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + elements[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= n; j++) {
            int idx = (i + j) % n;
            if(idx > i) {
                s.insert(dp[idx] - dp[i]);
            }
            else {
                s.insert(dp[idx] + dp[n - 1] - dp[i]);
            }
        }
    }
    return s.size();
}