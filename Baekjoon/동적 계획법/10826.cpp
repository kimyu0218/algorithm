#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string add_big_int(string a, string b) {
    string result = "";
    bool ceiling = false;
    int a_idx = a.length() - 1;
    int b_idx = b.length() - 1;
    
    while(a_idx >= 0 && b_idx >= 0) {
        int a_last = a[a_idx--] - '0';
        int b_last = b[b_idx--] - '0';
        int sum = a_last + b_last + ceiling;
        
        ceiling = (sum >= 10);
        if(sum >= 10) {
            sum -= 10;
        }
        result += to_string(sum);
    }
    
    while(b_idx >= 0) {
        int b_last = b[b_idx--] - '0';
        int sum = b_last + ceiling;
        
        ceiling = (sum >= 10);
        if(sum >= 10) {
            sum -= 10;
        }
        result += to_string(sum);
    }
    
    reverse(result.begin(), result.end());
    return ceiling ? '1' + result : result;
}


string solution(int n) {
    if(n <= 1) {
        return to_string(n);
    }
    
    vector<string> dp (n + 1, "0");
    
    dp[1] = "1";
    for(int i = 2; i <= n; i++) {
        dp[i] = add_big_int(dp[i - 2], dp[i - 1]);
    }
    return dp[n];
}

int main() {
    int n;
    
    cin >> n;
    
    cout << solution(n);
    return 0;
}