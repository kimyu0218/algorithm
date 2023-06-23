#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;
const int MAX = 3;
typedef long long ll;

char op[MAX];
bool visited[MAX];
int prior[MAX];
ll answer = 0;

int setOperator(string exp) { // 연산자 리턴
    map<char, int> m;
    for(int i = 0; i < exp.length(); i++) {
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
            m[exp[i]]++;
        }
    }
    int idx = 0, n = m.size();
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        op[idx++] = iter->first;
    }
    return idx;
}

void compute(int n, string exp) {
    map<char, int> m; // 연산자 우선순위 저장하는 맵
    for(int i = 0; i < n; i++) {
        m[op[i]] = prior[i];
    }

    stack<ll> s1; // 피연산자 저장
    stack<char> s2; // 연산자 저장
    string num = "";
    for(int i = 0; i < exp.length(); i++) {
        // 1. 연산자 발견
        if(exp[i] < '0' || exp[i] > '9') {
            s1.push(stol(num)); // 이전 피연산자 push
            num = "";

            // 1-1. 연산자 pop
            while(!s2.empty() && m[s2.top()] >= m[exp[i]]) { // 연산자 우선순위가 앞서는 경우 계산
                char opt = s2.top();
                s2.pop();

                ll curr = s1.top(); s1.pop();
                ll pre = s1.top(); s1.pop();
                if(opt == '+') {
                    s1.push(curr+pre);
                }
                else if(opt == '-') {
                    s1.push(pre-curr);
                }
                else if(opt == '*') {
                    s1.push(curr*pre);
                }
            }
            // 1-2. 연산자 push
            s2.push(exp[i]);
        }
            // 피연산자 발견
        else {
            num += exp[i];
        }
    }
    s1.push(stol(num)); // 마지막 피연산자 push

    while(!s2.empty()) {
        char opt = s2.top();
        s2.pop();

        ll curr = s1.top(); s1.pop();
        ll pre = s1.top(); s1.pop();
        if(opt == '+') {
            s1.push(curr+pre);
        }
        else if(opt == '-') {
            s1.push(pre-curr);
        }
        else if(opt == '*') {
            s1.push(curr*pre);
        }
    }

    ll result = s1.top(); s1.pop(); // 최종 결과값
    answer = max(answer, abs(result)); // 답 갱신
}

void backtracking(int cnt, int n, string exp) {
    if(cnt == n) { // 연산자 우선순위 설정 완료 -> 연산 시작
        compute(n, exp);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i]) { // 이미 사용한 우선순위 pass
            continue;
        }
        prior[cnt] = i;
        visited[i] = true; // 우선순위 i번 사용
        backtracking(cnt+1, n, exp);
        visited[i] = false; // 우선순위 i번 사용 취소
    }
}

ll solution(string expression) {
    int n = setOperator(expression); // n: 연산자 종류 개수
    backtracking(0, n, expression);
    return answer;
}