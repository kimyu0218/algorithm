#include <iostream>
#include <vector>

using namespace std;

int black_jack(int n, int m, vector<int> card) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(i == j || j == k || k == i) continue; // 중복 pass
                int sum = card[i] + card[j] + card[k];
                if(sum <= m) ans = max(sum, ans);
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> card (n, 0);
    for(int i = 0; i < n; i++) // 카드 입력
        cin >> card[i];

    cout << black_jack(n, m, card);
    return 0;
}