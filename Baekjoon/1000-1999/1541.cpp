#include <iostream>
#include <stack>

using namespace std;

int add(stack<int> &s) {
    int sum = 0;
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }
    return sum;
}

int min_answer(string input) {
    int ans = 0;

    stack<int> s; // 더해야 하는 수 저장
    string num = "";

    bool minus = false; // 스택에 들어있는 수를 더할 것인가 뺄 것인가
    for(int i = 0; i < input.length(); i++) {
        // 1. 숫자 나온 경우
        if(input[i] >= '0' && input[i] <= '9') {
            num += input[i];
            continue;
        }
        // 2. 연산자 나온 경우, 스택에 숫자 집어넣기
        s.push(stoi(num)); num = "";

        // 2-1. - 연산자가 처음 나온 경우, 이전에 스택에 있는 수는 더하고 다음 스택부터 마이너스
        if(input[i] == '-' && !minus) {
            ans += add(s);
            minus = true;
        }
    }
    if(num != "") s.push(stoi(num));

    if(minus) ans -= add(s);
    else ans += add(s);
    return ans;
}

int main() {
    string input;
    cin >> input;

    cout << min_answer(input);
    return 0;
}