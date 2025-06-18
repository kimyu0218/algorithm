#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<char> get_sorted_digits(int len, string str_n) {
    priority_queue<char> digits;

    for(int i = 0; i < len; i++) {
        digits.push(str_n[i]);
    }
    return digits;
}

long long solution(long long n) {
    string answer = "";
    string str_n = to_string(n);
    int len = str_n.length();
    priority_queue<char> digits = get_sorted_digits(len, str_n);

    while(!digits.empty()) {
        answer += digits.top();
        digits.pop();
    }
    return stoll(answer);
}