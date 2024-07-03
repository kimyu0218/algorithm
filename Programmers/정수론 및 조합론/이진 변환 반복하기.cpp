#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string remove_zero(string s) {
    string answer = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '0') {
            continue;
        }
        answer += s[i];
    }
    return answer;
}

string to_binary(int n) {
    string answer = "";
    while(n) {
        answer += to_string(n % 2);
        n /= 2;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

vector<int> solution(string s) {
    int turn = 0;
    int zero_cnt = 0;

    while(s != "1") {
        turn++;
        string first = remove_zero(s);
        string second = to_binary(first.length());
        zero_cnt += (s.length() - first.length());
        s = second;
    }
    return {turn, zero_cnt};
}