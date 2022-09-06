#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> score(n, 0);
    for(int i = 0; i < n; i++) // 점수 입력
       cin >> score[i];

    sort(score.begin(), score.end(), greater<>()); // 내림차순 정렬
    cout << score[k-1];
    return 0;
}