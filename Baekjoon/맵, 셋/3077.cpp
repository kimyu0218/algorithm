#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<string> ans; // 정답
map<string, int> test; // 현우가 적은 답안

int score(int n) { // 점수 계산
    int score = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) { // (j는 항상 i보다 뒷순서의 전투를 가리킨다)
            if(test[ans[i]] < test[ans[j]]) score++; // 상대적인 관계를 맞춘 경우
        }
    }
    return score;
}

int main() {
    int n;
    cin >> n;

    string battle;
    ans.assign(n, "");

    for(int i = 0; i < n; i++) { // 정답 입력 (전투 순서대로 입력)
        cin >> battle;
        ans[i] = battle;
    }
    for(int i = 0; i < n; i++) { // 현우 답안 입력 (key: 전투명, value: 순서)
        cin >> battle;
        test[battle] = i;
    }
    cout << score(n) << '/' << n*(n-1)/2; // 점수 출력
    return 0;
}