#include <iostream>

using namespace std;

typedef long long ll;

ll result = -1;

int digit[10];

void set_digit(int len, string str) {
    for(int i = 0; i < len; i++) {
        int idx = str[i] - '0';
        digit[idx]++;
    }
}

void backtracking(int len, int b, string c_str) {
    if(c_str.length() == len) {
        ll c = stol(c_str);
        if(c < b) {
            result = max(result, c);
        }
        return;
    }
    
    int start = 1 - (c_str.length() != 0);
    for(int i = start; i < 10; i++) {
        if(!digit[i]) {
            continue;
        }
        
        char ch = i + '0';
        digit[i]--;
        backtracking(len, b, c_str + ch);
        digit[i]++;
    }
}

ll solution(int a, int b) {
    string a_str = to_string(a);
    int a_len = a_str.length();
    
    set_digit(a_len, a_str);
    backtracking(a_len, b, "");
    
    return result;
}

int main() {
    int a, b;
    
    cin >> a >> b;

    cout << solution(a, b);    
    return 0;
}