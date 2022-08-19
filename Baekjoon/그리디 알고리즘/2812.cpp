#include <iostream>
#include <deque>

using namespace std;

string max_num(int n, int k, string number) {
    string answer = "";
    deque<char> dq;

    int cnt = 0; // (cnt : 지운 수 개수 count)
    for(int i = 0; i < n; i++) {
        // 1. 현재 숫자와 비교 후 숫자 지우기
        while(!dq.empty() && number[i] > dq.back() && cnt < k) {
            dq.pop_back(); cnt++;
        }
        // 2. 현재 숫자 사용하기
        dq.push_back(number[i]);
    }

    // k개의 숫자를 지우지 못한 경우
    while(dq.size() > n-k) dq.pop_back();

    while(!dq.empty()) {
        answer += dq.front();
        dq.pop_front();
    }
    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;

    string number;
    cin >> number;

    cout << max_num(n, k, number);
    return 0;
}