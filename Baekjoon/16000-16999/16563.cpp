#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MAX = 5000000; // 최댓값
vector<int> prime; // 어떤 소수를 약수로 가지는지 저장하는 벡터

void init_prime() { // 소수 세팅
    prime.assign(MAX+1, 0);
    for(int i = 2; i <= MAX; i++) prime[i] = i; // 모든 수를 소수라고 가정

    for(int i = 2; i <= sqrt(MAX); i++) {
        if(prime[i] == i) { // 소수인 경우
            for(int j = i * i; j <= MAX; j += i) {
                if(prime[j] == j)
                    prime[j] = i; // (j는 i를 소수로 가진다)
            }
        }
    }
}

vector<int> prime_fact(int k) { // 소인수분해
    vector<int> fact; // 소인수분해 결과값을 담는 벡터
    while(k != 1) {
        fact.push_back(prime[k]);
        k /= prime[k];
    }
    return fact;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n;

    init_prime();

    while(n--) {
        cin >> k;
        vector<int> fact = prime_fact(k);
        for(int i = 0; i < fact.size(); i++)
            cout << fact[i] << ' ';
        cout << '\n';
    }
    return 0;
}