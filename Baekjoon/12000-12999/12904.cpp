#include <iostream>
#include <algorithm>

using namespace std;

const int B = 'B';

int solution(string s, string t) {
    while(t.length() > s.length()) {
        char back = t.back();
        t = t.substr(0, t.length() - 1);

        if(back == B) {
            reverse(t.begin(), t.end());
        }
    }
    return s == t;
}

int main() {
    string s, t;

    cin >> s >> t;

    cout << solution(s, t);
    return 0;
}