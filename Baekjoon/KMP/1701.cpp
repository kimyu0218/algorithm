#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern) {
    int p = 0, n = pattern.length();
    vector<int> table(n, 0); // prefix와 suffix가 일치할 때의 그 길이

    for(int s = 1; s < n; s++) {
        while(p > 0 && pattern[s] != pattern[p]) {
            p = table[p-1];
        }
        if(pattern[s] == pattern[p]) { // s까지 일치하는 길이
            table[s] = ++p;
        }
    }
    return table;
}

int cubelang(string s) {
    int ans = 0, n = s.length();
    for(int i = 0; i < n; i++) {
        vector<int> table = makeTable(s.substr(i, n-i));
        for(int j = 0; j < n-i; j++) {
            ans = max(ans, table[j]);
        }
    }
    return ans;
}

int main() {
    string s;

    cin >> s;
    cout << cubelang(s);
    return 0;
}