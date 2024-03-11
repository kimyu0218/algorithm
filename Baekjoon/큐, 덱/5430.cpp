#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<string> init_deque(string input) {
    deque<string> result;

    string num = "";
    for(int i = 1; i < input.length() - 1; i++) {
        char ch = input[i];
        if(ch == ',') {
            result.push_back(num);
            num = "";
            continue;
        }
        num += ch;
    }
    if(num != "") {
        result.push_back(num);
    }
    return result;
}

string make_vector_string(bool is_reverse, deque<string> dq) {
    string result = "";

    if(is_reverse) {
        while(!dq.empty()) {
            result += dq.back() + ',';
            dq.pop_back();
        }
        return '[' + result.substr(0, result.length() - 1) + ']';
    }
    while(!dq.empty()) {
        result += dq.front() + ',';
        dq.pop_front();
    }
    return '[' + result.substr(0, result.length() - 1) + ']';
}

string solution(string p, string x) {
    deque<string> dq = init_deque(x);
    ㅏㅏ
    bool is_reverse = false;
    for(int i = 0; i < p.length(); i++) {
        char ch = p[i];
        if(ch == 'R') {
            is_reverse = !is_reverse;
            continue;
        }
        if(dq.empty()) {
            return "error";
        }
        if(is_reverse) {
            dq.pop_back();
        }
        else {
            dq.pop_front();
        }
    }
    return make_vector_string(is_reverse, dq);
}

int main() {
    int t, n;
    string p, x;

    cin >> t;

    while(t--) {
        cin >> p >> n >> x;

        cout << solution(p, x) << '\n';
    }
    return 0;
}