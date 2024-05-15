#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> score) {
    int answer = 0;
    int n = score.size();

    for(int i = n - 1; i >= 1; i--) {
        if(score[i] > score[i - 1]) {
            continue;
        }
        int before = score[i - 1];
        score[i - 1] = score[i] - 1;
        answer += (before - score[i - 1]);
    }
    return answer;
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