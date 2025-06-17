#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_binary(int n) {
    string answer = "";

    while(n) {
        answer += to_string(n % 2);
        n /= 2;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int count_one(string s) {
    int cnt = 0;

    for(int i = 0; i < s.length(); i++) {
        cnt += (s[i] == '1');
    }
    return cnt;
}

int solution(int n) {
    int answer = n + 1;
    int cnt = count_one(to_binary(n));

    while(true) {
        string bin = to_binary(answer);
        if(cnt == count_one(bin)) {
            return answer;
        }
        answer++;
    }
}