#include <iostream>
#include <map>
#include <cmath>

using namespace std;

const int MAX = 100000;
int prime[MAX+1];
map<int, int> fact;

void init_prime() { // 소수 세팅
    for(int i = 2; i <= MAX; i++) prime[i] = i;

    for(int i = 2; i <= sqrt(MAX); i++) {
        if(prime[i] != i) continue;
        for(int j = i * i; j <= MAX; j+=i) {
            if(prime[j] == j) prime[j] = i;
        }
    }
}

void multiply(int n) { // 곱하기
    n = abs(n); // (정수 여부만 판단하므로 부호 무시)
    while(n > 1) {
        fact[prime[n]]++;
        n /= prime[n];
    }
}

void divide(int n) { // 나누기
    n = abs(n); // (정수 여부만 판단하므로 부호 무시)
    while(n > 1) {
        fact[prime[n]]--;
        n /= prime[n];
    }
}

string mint_or_toothpaste() {
    for(auto iter = fact.begin(); iter != fact.end(); iter++) {
        if(iter->second < 0) return "toothpaste";
    }
    return "mint chocolate";
}

int main() {
    int n, num;
    char op;
    bool zero = false;
    cin >> n;

    init_prime(); // 소수 세팅

    cin >> num;
    if(num == 0) zero = true;
    multiply(num); n--; // 첫번째 수 세팅

    while(n--) {
        cin >> op >> num;
        if(num == 0) zero = true;
        else if(op == '*') multiply(num);
        else if(op == '/') divide(num);
    }

    cout << (zero ? "mint chocolate" : mint_or_toothpaste());
    return 0;
}