#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int int_sum(string s) {
    int sum = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            sum += s[i] - '0';
        }
    }
    return sum;
}

bool cmp(string &s1, string &s2) {
    if(s1.length() != s2.length()) {
        return s1.length() < s2.length();
    }
    int sum1 = int_sum(s1);
    int sum2 = int_sum(s2);
    if(sum1 != sum2) {
        return sum1 < sum2;
    }
    return s1 < s2;
}

vector<string> solution(vector<string> serial_num) {
    sort(serial_num.begin(), serial_num.end(), cmp);
    return serial_num;
}

int main() {
    int n;
    vector<string> serial_num;

    cin >> n;

    serial_num.assign(n, "");
    for(int i = 0; i < n; i++) {
        cin >> serial_num[i];
    }

    vector<string> sorted = solution(serial_num);
    for(int i = 0; i < n; i++) {
        cout << sorted[i] << '\n';
    }
    return 0;
}