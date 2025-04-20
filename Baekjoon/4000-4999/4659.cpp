#include <iostream>
#include <queue>

using namespace std;

const int ALPHA = 26;

vector<bool> visited;

bool is_vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

bool satisfy_cond1() {
    return visited['a' - 'a'] || visited['e' - 'a'] || visited['i' - 'a'] || visited['o' - 'a'] || visited['u' - 'a'];
}

bool satisfy_cond2(deque<char> dq) {
    if(dq.size() < 2) {
        return true;
    }
    char ch1 = dq.back();
    dq.pop_back();
    char ch2 = dq.back();
    dq.pop_back();
    return !(ch1 != 'e' && ch1 != 'o' && ch1 == ch2);
}

bool satisfy_cond3(deque<char> dq) {
    if(dq.size() < 3) {
        return true;
    }
    char ch1 = dq.back();
    dq.pop_back();
    char ch2 = dq.back();
    dq.pop_back();
    char ch3 = dq.back();
    dq.pop_back();
    return !(is_vowel(ch1) == is_vowel(ch2) && is_vowel(ch2) == is_vowel(ch3));
}

string solution(string password) {
    string acceptable = "<" + password + "> is acceptable.";
    string not_acceptable = "<" + password + "> is not acceptable.";

    deque<char> dq;
    visited.assign(ALPHA, false);

    int n = password.length();
    for(int i = 0; i < n; i++) {
        char ch = password[i];

        dq.push_back(ch);
        if(!satisfy_cond2(dq) || !satisfy_cond3(dq)) {
            return not_acceptable;
        }
        visited[ch - 'a'] = true;
    }
    return satisfy_cond1() ? acceptable : not_acceptable;
}

int main() {
    string input;

    while(true) {
        cin >> input;

        if(input == "end") {
            break;
        }
        cout << solution(input) << '\n';
    }
    return 0;
}