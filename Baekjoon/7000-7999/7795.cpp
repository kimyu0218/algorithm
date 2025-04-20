#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    vector<int> dp (n + 1, 0);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    for(int i = 0; i < n; i++) {
        dp[i] = m;
        for(int j = 0; j < m; j++) {
            if(b[j] >= a[i]) {
                dp[i] = j;
                break;
            }
        }
        dp[n] += dp[i];
    }
    return dp[n];
}

int main() {
    int t, n, m;
    vector<int> a, b;

    cin >> t;
    while(t--) {
        cin >> n >> m;

        a.assign(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        b.assign(m, 0);
        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }

        cout << solution(a, b) << '\n';
    }
    return 0;
}