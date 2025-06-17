#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count_zero(string x) {
    int cnt = 0;

    for(int i = 0; i < x.length(); i++) {
        cnt += (x[i] == '0');
    }
    return cnt;
}

string remove_zero(string x) {
    string answer = "";

    for(int i = 0; i < x.length(); i++) {
        if(x[i] == '0') {
            continue;
        }
        answer += x[i];
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
    vector<int> answer = { 0, 0 };

    while(s != "1") {
        answer[0]++;
        answer[1] += count_zero(s);
        string removed = remove_zero(s);
        s = to_binary(removed.length());
    }
    return answer;
}