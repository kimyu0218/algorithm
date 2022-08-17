#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_weight(vector<int> w, int n) {
    int max = 0; // (1, max) : 1부터 max까지 측정 가능
    for(int i = 0; i < n; i++) {
        // w[i] : 새로운 추 -> (1+w[i], max+w[i]) 측정 가능
        // max >= 1 + w[i] 를 만족해야 빈 구간이 생기지 않음
        if(max + 1 < w[i]) return max + 1; // 측정할 수 없는 무게 발견
        max += w[i];
    }
    return max + 1;
}

int main() {
    int n; // 저울추 개수
    cin >> n;

    vector<int> w(n, 0); // 저울추 무게 저장하는 배열
    for(int i = 0; i < n; i++) // 저울추 무게 입력
        cin >> w[i];
    sort(w.begin(), w.end());

    cout << min_weight(w, n);
    return 0;
}