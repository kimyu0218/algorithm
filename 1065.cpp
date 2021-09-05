#include <iostream>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int digit(int num, int index) { // 자릿수 반환
    return (int) (num/pow(10, index));
}

int find(int n) {
    int result = 0, x = 1;

    while(x <= n) {
        int tmp = x;

        queue<int> q; // 자릿수 저장하는 큐
        bool flag = false;
        for(int i = 2; i >= 0; i--) { // (10^2 -> 10^1 -> 10^0)
            if(digit(tmp, i)) {
                q.push(digit(tmp, i));
                flag = true;
            }
            else if(flag || i == 0) q.push(digit(tmp, i));
            tmp %= (int) pow(10, i);
        }

        stack<int> s; // 자릿수 등차 저장하는 스택
        int pre = q.front(); q.pop();
        while(!q.empty()) {
            int now = q.front(); q.pop();
            s.push(pre-now);
            pre = now;
        }

        flag = true;
        if(!s.empty()) {
            pre = s.top();
            s.pop();
        }
        while(!s.empty()) {
            int now = s.top(); s.pop();
            if(pre != now) { // 등차수열 아닌 경우
                flag = false;
                break;
            }
            pre = now;
        }
        if(flag) result++;
        x++;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    cout << find(n);
    return 0;
}