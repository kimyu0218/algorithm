#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int n = arr.size();
    vector<vector<int>> dp (n + 1, vector<int> (2, 1));
    
    for(int i = 1; i < n; i++) {
        if(arr[i] >= arr[i - 1]) {
            dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
            dp[n][0] = max(dp[n][0], dp[i][0]);
        }
        if(arr[i] <= arr[i - 1]) {
            dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
            dp[n][1] = max(dp[n][1], dp[i][1]);
        }
    }
    return max(dp[n][0], dp[n][1]);
}

int main() {
    int n;
    vector<int> arr;
    
    cin >> n;
    
    arr.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << solution(arr);
    return 0;
}