#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

vector<int> rank_size(int n, vector<pi> people) { // 덩치 등수 반환
    vector<int> ranking (n, 0);
    for(int i = 0; i < n; i++) { // i 사람의 랭킹 구하기
        int bigger = 0;
        for(int j = 0; j < n; j++) { // j : 비교 대상
            if(i == j) continue;
            if(people[j].first > people[i].first && people[j].second > people[i].second) bigger++;
        }
        ranking[i] = bigger + 1;
    }
    return ranking;
}

int main() {
    int n;
    cin >> n;

    vector<pi> people (n, {0, 0});
    for(int i = 0; i < n; i++) // 몸무게와 키 입력
        cin >> people[i].first >> people[i].second;

    vector<int> ranking = rank_size(n, people);
    for(int i = 0; i < n; i++) // 등수 출력
        cout << ranking[i] << ' ';
    return 0;
}