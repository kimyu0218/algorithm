#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<double> get_operands(stack<double> &s) {
    double operand1 = s.top();
    s.pop();
    double operand2 = s.top();
    s.pop();
    return { operand1, operand2 };
}

double calculate(char op, double operand1, double operand2) {
    switch(op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
    }
}

double solution(string postfix, vector<int> num) {
    stack<double> s;

    for(int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if(ch >= 'A' && ch <= 'Z') {
            s.push(num[ch - 'A']);
            continue;
        }

        vector<double> operands = get_operands(s);
        double result = calculate(ch, operands[1], operands[0]);
        s.push(result);
    }
    return s.top();
}

int main() {
    int n;
    string postfix;
    vector<int> num;

    cin >> n >> postfix;

    num.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cout << fixed;
    cout.precision(2);
    cout << solution(postfix, num);
    return 0;
}