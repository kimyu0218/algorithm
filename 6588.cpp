#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MAX_NUM = 1000000;
vector<bool> is_prime; // 소수 여부 저장하는 벡터

void isPrime() { // 소수 찾기
    is_prime.assign(MAX_NUM+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= sqrt(MAX_NUM); i++) {
        if(!is_prime[i]) continue;
        for(int j = i * i; j <= MAX_NUM; j += i)
            is_prime[j] = false;
    }
}

string primeSum(int n) {
    for(int i = 3; i <= n/2; i+=2) {
        if(is_prime[i] && is_prime[n-i])
            return to_string(n) + " = "+ to_string(i) + " + " + to_string(n-i);
    }
    return "Goldbach's conjecture is wrong.";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    isPrime(); // 소수 구하기

    while(true) {
        cin >> n;
        if(n == 0) break;
        cout << primeSum(n) << '\n';
    }
    return 0;
}