#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

const int H = 1e5 * 5 + 1;

int top_dp[H + 1];
int bottom_dp[H + 1];

void prefix_sum(int n, int h, vector<int> lengths) {
    for(int i = 0; i < n; i++) {
        int len = lengths[i];
        if(i % 2) {
            top_dp[len]++;
        }
        else {
            bottom_dp[h - (len - 1)]++;
        }
    }

    for(int i = 1; i <= h; i++) {
        bottom_dp[i] += bottom_dp[i - 1];
        top_dp[h - i] += top_dp[h - (i - 1)];
    }
}

pi solution(int h, vector<int> lengths) {
    pi answer;
    int n = lengths.size();
    vector<int> dp (h, 0);

    prefix_sum(n, h, lengths);

    answer = { top_dp[1] + bottom_dp[1], 1 };
    for(int i = 2; i <= h; i++) {
        int sum = top_dp[i] + bottom_dp[i];
        if(sum < answer.first) {
            answer = { sum, 1 };
        }
        else if(sum == answer.first) {
            answer.second++;
        }
    }
    return answer;
}

int main() {
    int n, h;
    vector<int> lengths;

    cin >> n >> h;

    lengths.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    pi answer = solution(h, lengths);

    cout << answer.first << ' ' << answer.second;
    return 0;
}