#include <iostream>
#include <string>
#include <stack>

using namespace std;

void assignBigSmall(string a, string b, string &big, string &small) { // 큰 수, 작은 수 할당하기
    if(a.length() > b.length() || a == b) { big = a; small =b; }
    else if(a.length() < b.length()) { small = a; big = b; }
    else {
        for(int i = 0; i < a.length(); i++) {
            if(a[i] > b[i]) { big = a; small = b; }
            else if(a[i] < b[i]) { small = a; big = b; }
        }
    }
}

void addLargeNum(string &big, string &small) { // 더하기
    stack<int> result;
    int tmp, remain; // (tmp: 연산용, remain 올림용)
    int i1 = big.length()-1, i2 = small.length()-1; // 각각 큰 수, 작은 수 인덱스

    bool flag = false; // 올림 여부 표시
    while(i1 >= 0 && i2 >= 0) {
        tmp = small[i2]-'0' + big[i1]-'0';
        if(flag) {
            tmp += remain;
            flag = false;
            remain = 0;
        }
        if(tmp/10) {
            flag = true;
            remain = (int) tmp/10;
        }
        result.push(tmp%10);
        i1--; i2--;
    }
    while(i1 >= 0) {
        tmp = big[i1] - '0';
        if(flag) {
            tmp += remain;
            flag = false;
            remain = 0;
        }
        if(tmp/10) {
            flag = true;
            remain = (int) tmp/10;
        }
        result.push(tmp%10);
        i1--;
    }
if(flag) result.push(remain);

while(!result.empty()) { // 덧셈 결과 출력
cout << result.top();
result.pop();
}
}

void compute(const string a, const string b) {
    string big, small;
    assignBigSmall(a, b, big, small); // 큰 수, 작은 수 할당하기
    addLargeNum(big, small); // 더하기
}

int main() {
    string a, b;
    cin >> a >> b;
    compute(a,b);
    return 0;
}