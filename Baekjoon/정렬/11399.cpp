#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcTime(int n, vector<int> &p) { // 돈을 인출하는데 필요한 시간의 합 구하기
    int sum = 0, time = 0;
    for(int i = 0; i < n; i++) {
        time += p[i]; // i번째 작업을 실행하는데 걸린 시간
        sum += time;
    }
    return sum;
}

int main() {
    int n; // 사람 수
    vector<int> p; // 사람이 돈을 인출하는데 걸리는 시간

    // 입력
    cin >> n;
    p.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p.begin(), p.end()); // 오름차순 정렬

    // 연산 & 출력
    cout << calcTime(n, p);
    return 0;
}