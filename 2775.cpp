#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> apart; // 아파트 세대별 인원 저장
vector<int> peopleNum;

void apartment(int floor, int n) { // 아파트 세대별 인원 계산하기
    if(floor == 0) { // 0층
        for(int i = 1; i <= n; i++)
            apart[floor][i-1] = i;
    }
    else { // 0층 아닌 경우
        int people = 0;
        for(int i = 1; i <= n; i++) {
            people += apart[floor-1][i-1];
            apart[floor][i-1] = people;
        }
    }
}

void resident(int k, int n, int t) { // 해당 세대 인원 계산하기
    for(int i = 0; i <= k; i++) // 아파트 세대별 인원 계산하기
        apartment(i, n);
    peopleNum[t] = apart[k][n-1];
}

int main() {
    int t, k, n;
    cin >> t;

    peopleNum.assign(t, 0);
    for(int i = 0; i < t; i++) {
        cin >> k >> n;
        apart.assign(k+1, vector<int>(n, 0));
        resident(k, n, i); // 해당 세대 인원 계산하기
    }

    for(int i = 0; i < t; i++) // 해당 세대 인원 출력하기
        cout << peopleNum[i] << '\n';
    return 0;
}