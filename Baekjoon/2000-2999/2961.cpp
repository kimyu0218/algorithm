#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;
typedef pair<int, int> pi;

int solution(int n, vector<pi> &ingredient) {
    int answer = INF;
    for(int i = 1; i < (1 << n); i++) { // i : 경우의 수
        int s = 1, b = 0;
        for(int j = 0; j < n; j++) { // j : 재료 인덱스
            if(i & (1 << j)) {
                s *= ingredient[j].first;
                b += ingredient[j].second;
            }
        }
        answer = min(answer, abs(s-b));
    }
    return answer;
}

int main() {
    int n;
    vector<pi> ingredient;

    cin >> n;
    ingredient.assign(n, {});
    for(int i = 0; i < n; i++) {
        cin >> ingredient[i].first >> ingredient[i].second;
    }

    cout << solution(n, ingredient);
    return 0;
}