#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isBalancedBracket(string p) { // 균형잡힌 괄호 문자열인가
    int cnt = 0; // 여는 괄호 개수 카운트
    for(int i = 0; i < p.length(); i++) {
        if(p[i] == '(') {
            cnt++;
        }
    }
    return cnt == p.length()/2;
}

bool isCorrectBracket(string p) { // 올바른 괄호 문자열인가
    stack<int> s;
    for(int i = 0; i < p.length(); i++) {
        if(p[i] == '(') { // 여는 괄호 push
            s.push(p[i]);
        }
        else if(s.empty()) { // 닫는 괄호 나왔지만 짝을 이루는 여는 괄호 없음
            return false;
        }
        else { // 짝을 이루는 여는 괄호 pop
            s.pop();
        }
    }
    return s.empty();
}

string solution(string p) {
    if(p == "") { // 1. 빈 문자열은 빈 문자열 반환
        return "";
    }
    if(isCorrectBracket(p)) { // 올바른 괄호 문자열 바로 반환
        return p;
    }

    int len = 2; // 균형잡힌 문자열이기 위해서는 괄호 개수 반드시 짝수개
    while(true) {
        // 2. 균형잡힌 문자열로 분리
        string u = p.substr(0, len);
        string v = p.substr(len, p.length()-len);
        if(!isBalancedBracket(u)) { // u가 균형잡힌 문자열이 되기까지 길이 2씩 증가
            len += 2;
            continue;
        }
        // 3. u가 올바른 괄호 문자열이면 v에 대해 실행 후 이어붙이기
        if(isCorrectBracket(u)) {
            return u + solution(v);
        }
        // 4. u가 올바른 괄호 문자열이 아닌 경우
        string result = "(";
        result += solution(v);
        result += ")";
        for(int i = 1; i < u.length()-1; i++) {
            if(u[i] == '(') {
                result += ")";
            }
            else {
                result += "(";
            }
        }
        return result;
    }
}