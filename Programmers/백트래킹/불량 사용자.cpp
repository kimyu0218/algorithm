#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> answer; // 제재 아이디 경우의 수 저장

vector<string> blacklist(string check, vector<string> &user_id) { // 불량 아이디 check가 발견할 수 있는 아이디 목록 반환
    vector<string> s;
    int len = check.length(); // check의 길이

    for(int i = 0; i < user_id.size(); i++) {
        string cmp = user_id[i]; // check와 비교할 사용자 아이디
        if(len != cmp.length()) { // 글자 수가 다르면 바로 pass
            continue;
        }

        bool find = true;
        for(int j = 0; j < len; j++) {
            if(check[j] == '*') {
                continue;
            }
            if(check[j] != cmp[j]) { // 문자 일치하지 않음
                find = false;
                break;
            }
        }
        if(find) { // check와 일치하는 사용자 아이디 찾음
            s.push_back(cmp);
        }
    }
    return s;
}

// (idx번째 banned_id)
void backtracking(int idx, int n, vector<vector<string>> &candidate, set<string> s) {
    if(idx == n) { // 기저조건
        string result = ""; // 제재 아이디 목록 문자열로 저장
        for(auto iter = s.begin(); iter != s.end(); iter++) {
            result += (*iter + ' ');
        }
        answer.insert(result);
        return;
    }

    for(int i = 0; i < candidate[idx].size(); i++) {
        string tmp = candidate[idx][i]; // banned_id[idx]가 찾은 사용자 아이디
        if(s.find(tmp) == s.end()) { // 해당 사용자 아이디가 아직 사용되지 않은 경우
            s.insert(tmp);
            backtracking(idx+1, n, candidate, s); // 다음 banned_id 탐색
            s.erase(tmp);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int n = banned_id.size(); // 불량 아이디 개수
    vector<vector<string>> candidate(n, vector<string> (0)); // 불량 아이디별 발견할 수 있는 사용자 아이디

    for(int i = 0; i < n; i++) { // 사용자 아이디 검색
        candidate[i] = blacklist(banned_id[i], user_id);
    }

    set<string> s;
    backtracking(0, n, candidate, s); // 경우의 수 만들기
    return answer.size(); // 경우의 수 반환
}