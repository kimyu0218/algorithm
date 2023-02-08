#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

const int SIZE = 10, MAX = 1e8;
vector<bool> is_prime;
int num[SIZE];
set<int> s;

void setPrime() { // 소수 세팅
    is_prime.assign(MAX, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < sqrt(MAX); i++) {
        if(!is_prime[i]) {
            continue;
        }
        for(int j = i*2; j < MAX; j+=i) {
            is_prime[j] = false;
        }
    }
}

void setNum(int n, string numbers) { // 숫자 세팅
    for(int i = 0; i < n; i++) {
        num[numbers[i]-'0']++;
    }
}

void initialize(int n, string numbers) {
    setPrime();
    setNum(n, numbers);
}

void backtracking(int cnt, int n, int val) {
    if(cnt == n) { // 기저조건 (== 숫자 다 사용함)
        return;
    }
    for(int i = 0; i < SIZE; i++) {
        if(num[i]) { // 여분의 i 남아있음
            num[i]--; // 사용
            int new_val = val*10 + i; // 새로운 숫자 조합하기
            s.insert(new_val);
            backtracking(cnt+1, n, new_val);
            num[i]++; // 사용 취소
        }
    }
}

int cntPrime() { // 소수 개수 세기
    int cnt = 0;
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        if(is_prime[*iter]) {
            cnt++;
        }
    }
    return cnt;
}

int solution(string numbers) {
    int n = numbers.length();
    initialize(n, numbers);
    backtracking(0, n, 0); // 가능한 모든 숫자 조합하기

    return cntPrime();
}