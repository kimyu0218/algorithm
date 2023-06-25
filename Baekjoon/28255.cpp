#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

string prefix(string s) {
    int n = s.length();
    int slice = ceil((double) n/3);
    return s.substr(0, slice);
}

string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string tail(string s) {
    return s.substr(1, s.length()-1);
}

bool solution(string s) {
    string s_ = prefix(s);
    if(s == s_ + rev(s_) + s_) {
        return true;
    }
    if(s == s_ + tail(rev(s_)) + s_) {
        return true;
    }
    if(s == s_ + rev(s_) + tail(s_)) {
        return true;
    }
    return s == s_ + tail(rev(s_)) + tail(s_);
}

int main() {
    int t;
    string s;

    cin >> t;
    while(t--) {
        cin >> s;
        cout << solution(s) << '\n';
    }
    return 0;
}