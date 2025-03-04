#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MAX = 1000000;
vector<bool> is_prime;

void init_prime() { // 소수 세팅
    is_prime.assign(MAX+1, true);
    for(int i = 2; i <= sqrt(MAX); i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= MAX; j += i)
                is_prime[j] = false;
        }
    }
};

void goldbach(int n) { // 골드바흐의 추측 검증
    for(int i = 2; i <= n/2; i++) {
        // (i + (n-i) == n)
        if(is_prime[i] && is_prime[n-i]) { // 두 소수의 합으로 n을 나타낼 수 있음
            cout << n << " = " << i << " + " << n-i <<'\n';
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong.\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    init_prime();

    while(true) {
        cin >> n;
        if(n == 0) break;
        goldbach(n);
    }
    return 0;
}