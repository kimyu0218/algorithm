#include <iostream>
#include <stack>

using namespace std;
stack<int> s;
string result = "";

void push(int &last) {
    s.push(++last);
    result += "+\n";
}

void pop() {
    s.pop();
    result += "-\n";
}

int main() {
    int n, num, last = 0; // last : 마지막으로 스택에 push된 숫자
    cin >> n;

    while(n--) {
        cin >> num;
        // 1. push
        if(num > last) {
            while(num > last) push(last); // 스택에 num이 될때까지 push
            pop();
        }
        // 2. pop (top만 검사 : 1부터 n까지의 수열이므로 중간에 하나의 숫자가 누락되면 NO)
        else if(!s.empty() && num == s.top()) pop();
        // 3. NO
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << result;

    return 0;
}