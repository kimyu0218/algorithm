#include <iostream>
#include <stack>

using namespace std;

int main() {
    int k, input, sum = 0;
    cin >> k;

    stack<int> s;
    while(k--) {
        cin >> input;
        if(input != 0) s.push(input);
        else s.pop();
    }

    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum;

    return 0;
}