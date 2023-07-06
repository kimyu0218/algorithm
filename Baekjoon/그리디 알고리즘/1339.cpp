#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
const int CNT = 26;
typedef long long ll;

struct info {
    char ch; // 알파벳
    ll sum; // 자릿수 합
};
int num[CNT]; // 알파벳을 숫자로 치환한 값

bool cmp(const info &i1, const info &i2) { // 자릿수 합 내림차순
    return i1.sum > i2.sum;
}

ll maxSum(int n, vector<string> &s, vector<info> &v) {
    // 알파벳 숫자로 치환하기
    int digit = 9;
    for(int i = 0; i < v.size(); i++) {
        char ch = v[i].ch;
        num[ch-'A'] = digit--;
    }

    // 최댓값 구하기
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        string tmp = "";
        for(int j = 0; j < s[i].length(); j++) {
            tmp += to_string(num[s[i][j]-'A']);
        }
        sum += stoll(tmp);
    }
    return sum;
}

int main() {
    int n;
    vector<string> s;
    vector<ll> alpha; // 알파벳별 자릿수 합 저장

    cin >> n;
    s.assign(n, "");
    alpha.assign(CNT, 0);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        int len = s[i].length();
        for(int j = 0; j < len; j++) {
            char ch = s[i][j];
            alpha[ch-'A'] += pow(10, len-1-j);
        }
    }

    vector<info> v;
    for(int i = 0; i < CNT; i++) {
        if(alpha[i] == 0) { // 사용되지 않은 알파벳 pass
            continue;
        }
        v.push_back({(char) ('A' + i), alpha[i]});
    }
    sort(v.begin(), v.end(), cmp); // 자릿수 합 내림차순

    cout << maxSum(n, s, v);
    return 0;
}