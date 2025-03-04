#include <iostream>
#include <vector>

using namespace std;

int solution(int t, int p, vector<int> scores) {
    int n = scores.size();
    if(n == 0) {
        return 1;
    }

    if(t > scores[0]) {
        return 1;
    }

    int rank = 1;
    for(int i = 1; i < n; i++) {
        if(t > scores[i]) {
            return (t == scores[i - 1]) ? rank : i + 1;
        }
        if(scores[i] == scores[i - 1]) {
            continue;
        }
        rank = i + 1;
    }

    if(n + 1 > p) {
        return -1;
    }
    return (t == scores[n - 1]) ? rank : n + 1;
}

int main() {
    int n, t, p;
    vector<int> scores;

    cin >> n >> t >>p;

    scores.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    cout << solution(t, p, scores);
    return 0;
}