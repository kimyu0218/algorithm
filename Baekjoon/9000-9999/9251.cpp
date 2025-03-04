#include <iostream>
#include <vector>

using namespace std;

int lcs(string s1, string s2) { // lcs : 최장 공통 부분 수열
    int len1 = s1.length(), len2 = s2.length();
    vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

    for(int i = 1; i <= len1; i++) { // (i : s1의 인덱스)
        for(int j = 1; j <= len2; j++) { // (j : s2의 인덱스)
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1; // 1. 같은 문자
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // 2. 다른 문자
        }
    }
    return dp[len1][len2];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout <<lcs(s1, s2);
    return 0;
}