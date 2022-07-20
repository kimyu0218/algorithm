#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 987;
bool possible[MAX+1] = { false, }; // 답변 가능 여부 저장하는 배열

struct baseball{
    string num;
    int strike, ball;
};

pair<int, int> cmp(string s1, string s2) {
    int strike = 0, ball = 0;
    for(int i = 0; i < 3; i++) {
        if(s1[i] == s2[i]) strike++; // 스트라이크 카온트
        else if(s1.find(s2[i]) != string::npos) ball++; // 볼 카운트
    }
    return {strike, ball};
}

void game(vector<baseball> &q, int n) {
    for(int i = 123; i <= 987; i++) {
        string s = to_string(i);

        // 1. 1부터 9 사이의 서로 다른 수를 만족하지 못하는 경우
        if(s[0] == '0' || s[1] == '0' || s[2] == '0') continue;
        if(s[0] == s[1] || s[1] == s[2] || s[2] == s[0]) continue;

        // 2. i가 민혁이의 물음들과 스트라이크, 볼 수가 일치하는가
        bool flag = true;
        for(int j = 0; j < n; j++) { // question과 비교
            pair<int, int> tmp = cmp(s, q[j].num);
            if(q[j].strike != tmp.first || q[j].ball != tmp.second) { // 2-1. 가능성 없는 답변
                flag = false;
                break;
            }
        }
        if(flag) possible[i] = true; // 2-2. 가능성 있는 답변
    }
}

int possible_cnt() { // 가능한 답변 개수 세기
    int cnt = 0;
    for(int i = 123; i <= 987; i++) {
        if(possible[i]) cnt++;
    }
    return cnt;
}

int main() {
    int n, num, strike, ball;
    cin >> n;

    vector<baseball> question;
    question.assign(n, baseball{"", 0, 0});
    for(int i = 0; i < n; i++)
        cin >> question[i].num >> question[i].strike >> question[i].ball;

    game(question, n);
    cout << possible_cnt();
    return 0;
}