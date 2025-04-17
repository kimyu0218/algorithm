#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int CNT = 5;
const int TOTAL_CNT = 8;

typedef pair<int, int> pi;

bool cmp(pi &p1, pi &p2) {
    if(p1.first != p2.first) {
        return p1.first > p2.first;
    }
    return p1.second < p2.second;
}

void solution(vector<int> scores) {
    vector<pi> sorted (TOTAL_CNT, {0, 0});

    for(int i = 0; i < TOTAL_CNT; i++) {
        sorted[i] = { scores[i], i + 1 };
    }
    sort(sorted.begin(), sorted.end(), cmp);

    int sum = 0;
    vector<int> quiz_num (CNT, 0);
    for(int i = 0; i < CNT; i++) {
        sum += sorted[i].first;
        quiz_num[i] = sorted[i].second;
    }
    sort(quiz_num.begin(), quiz_num.end());

    cout << sum << '\n';
    for(int i = 0; i < CNT; i++) {
        cout << quiz_num[i] << ' ';
    }
}

int main() {
    vector<int> scores (TOTAL_CNT, 0);
    for(int i = 0; i < TOTAL_CNT; i++) {
        cin >> scores[i];
    }

    solution(scores);
    return 0;
}