#include <string>

using namespace std;

bool is_upper_case(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool is_lower_case(char ch) {
    return ch >= 'a' && ch <= 'z';
}

char to_upper_case(char ch) {
    return ch - 'a' + 'A';
}

char to_lower_case(char ch) {
    return ch - 'A' + 'a';
}

string solution(string s) {
    string answer = s;

    if(is_lower_case(answer[0])) {
        answer[0] = to_upper_case(answer[0]);
    }

    for(int i = 1; i < s.length(); i++) {
        if(answer[i - 1] == ' ' && is_lower_case(answer[i])) {
            answer[i] = to_upper_case(answer[i]);
        }
        else if(answer[i - 1] != ' ' && is_upper_case(answer[i])) {
            answer[i] = to_lower_case(answer[i]);
        }
    }
    return answer;
}