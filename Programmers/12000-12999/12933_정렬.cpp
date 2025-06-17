#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> get_digits(int len, string str_n) {
    vector<char> digits (len, '\0');

    for(int i = 0; i < len; i++) {
        digits[i] = str_n[i];
    }
    return digits;
}

long long solution(long long n) {
    string answer = "";
    string str_n = to_string(n);
    int len = str_n.length();
    vector<char> digits = get_digits(len, str_n);

    sort(digits.begin(), digits.end(), greater<>());
    for(int i = 0; i < len; i++) {
        answer += digits[i];
    }
    return stoll(answer);
}