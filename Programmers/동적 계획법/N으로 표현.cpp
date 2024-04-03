#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int INF = 9;
const int MAX = 1e8;

void make_n_string(int N, queue<int> &q, set<int> &s, vector<int> &dp) {
    int n = N;
    int cnt = 0;

    while(++cnt < INF) {
        q.push(n);
        s.insert(n);
        dp[n] = cnt;
        n = stoi(to_string(n) + to_string(N));
    }
}

int solution(int N, int number) {
    int answer = 0;

    vector<int> dp(MAX, INF);
    set<int> s;
    queue<int> q;

    make_n_string(N, q, s, dp);

    dp[1] = min(dp[1], 2);
    q.push(1);
    s.insert(1);

    while(!q.empty()) {
        int n = q.front();
        q.pop();

        if(n == number) {
            return dp[n];
        }

        if(dp[n] + 1 == INF) {
            continue;
        }

        vector<int> tmp;
        for(auto iter = s.begin(); iter != s.end(); iter++) {
            int m = *iter;
            int new_w = dp[n] + dp[m];

            if(new_w >= INF) {
                continue;
            }

            int plus = n + m;
            if(plus < MAX && dp[plus] > new_w) {
                dp[plus] = new_w;
                q.push(plus);
                tmp.push_back(plus);
            }

            int minus = n - m;
            if(minus >= 0 && dp[minus] > new_w) {
                dp[minus] = new_w;
                q.push(minus);
                tmp.push_back(minus);
            }

            int multi = n * m;
            if(multi >= 0 && multi < MAX && dp[multi] > new_w) {
                dp[multi] = new_w;
                q.push(multi);
                tmp.push_back(multi);
            }

            if(m == 0) {
                continue;
            }
            int div = n / m;
            if(div >= 0 && dp[div] > new_w) {
                dp[div] = new_w;
                q.push(div);
                tmp.push_back(div);
            }
        }

        for(int i = 0; i < tmp.size(); i++) {
            s.insert(tmp[i]);
        }
    }
    return -1;
}