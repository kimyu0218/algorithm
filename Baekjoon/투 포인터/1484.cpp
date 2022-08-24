#include <iostream>

using namespace std;

void find_weight(int g) {
    bool find = false;
    int left = 1, right = 2; // 이전 몸무게, 현재 몸무게

    int diff = right * right - left * left;
    while(left < right) {
        if(diff == g) { // 1. 가능한 몸무게 발견
            find = true;
            cout << right << '\n';
            right++;
        }
        else if(diff < g) right++; // 2. 현재 몸무게 늘리기
        else left++; // 3. 이전 몸무게 늘리기
        diff = right * right - left * left;
    }
    if(!find) cout << -1; // 가능한 몸무게가 없는 경우
}

int main() {
    int g;
    cin >> g;

    find_weight(g);
    return 0;
}