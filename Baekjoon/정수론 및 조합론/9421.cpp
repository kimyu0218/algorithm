#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

const int MAX = 1e6;
vector<bool> prime; // 소수 여부 저장

void setPrime() { // 소수 세팅
    prime.assign(MAX+1, true);
    for(int i = 2; i <= sqrt(MAX); i++) {
        if(!prime[i]) continue; // (소수 아닌 경우 pass)
        for(int j = i * i; j <= MAX; j += i) { // (소수 i의 배수는 소수가 아님)
            prime[j] = false;
        }
    }
}

bool makeOne(int n) { // 상근수 여부 반환
    set<int> visited;

    while(n != 1) {
        // 무한 루프 방지 (이미 n으로 1을 만들 수 없었음)
        if(visited.find(n) != visited.end()) return false;
        visited.insert(n); // n으로 1 만들기 시도

        int sum = 0; // 각 자리수의 제곱의 합
        string num = to_string(n);
        for(int i = 0; i < num.size(); i++) {
            int digit = num[i] - '0';
            sum += (digit * digit);
        }
        n = sum;
    }
    return true;
}

vector<int> findNum(int n) { // 소수이면서 상근수인 수 찾기
    vector<int> result;
    for(int i = 2; i <= n; i++) {
        if(!prime[i]) continue; // 소수가 아닌 경우 pass
        if(makeOne(i)) result.push_back(i); // 소수 상근수 찾음
    }
    return result;
}

int main() {
    setPrime(); // 소수 세팅

    int n;
    cin >> n;

    vector<int> result = findNum(n); // n보다 작거나 같은 소수 상근수
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    return 0;
}