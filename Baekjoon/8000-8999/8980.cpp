#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
    int from, to, cnt;
};

bool cmp(info &i1, info &i2) {
    if(i1.to != i2.to) {
        return i1.to < i2.to;
    }
    return i1.from < i2.from;
}

int solution(int n, int c, vector<info> boxes) {
    int result = 0;
    vector<int> dp(n, 0);

    sort(boxes.begin(), boxes.end(), cmp);

    for(int i = 0; i < boxes.size(); i++) {
        int from = boxes[i].from - 1;
        int to = boxes[i].to - 1;

        int cnt = boxes[i].cnt;
        for(int j = from; j < to; j++) {
            if(dp[j] + cnt <= c) {
                continue;
            }
            cnt = c - dp[j];
        }

        result += cnt;
        for(int j = from; j < to; j++) {
            dp[j] += cnt;
        }
    }
    return result;
}

int main() {
    int n, c, m;
    vector<info> boxes;

    cin >> n >> c >> m;

    boxes.assign(m, {0, 0, 0});
    for(int i = 0; i < m; i++) {
        cin >> boxes[i].from >> boxes[i].to >> boxes[i].cnt;
    }

    cout << solution(n, c, boxes);
    return 0;
}