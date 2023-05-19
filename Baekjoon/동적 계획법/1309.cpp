#include <iostream>
#include <vector>

using namespace std;

int lcs(int n, vector<int> &box) {
    vector<int> dp (n+1, 1);
    for(int i = 0; i < n; i++) { // i : 뒤
        for(int j = 0; j < i; j++) { // j : 앞
            if(box[i] > box[j]) { // j 상자 넣을 수 있음
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        dp[n] = max(dp[n], dp[i]);
    }
    return dp[n];
}

int main() {
    int n;
    vector<int> box;

    cin >> n;
    box.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> box[i];
    }

    cout << lcs(n, box);
    return 0;
}