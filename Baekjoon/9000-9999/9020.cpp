#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1e4;

typedef pair<int, int> pi;

vector<bool> is_prime;

void set_prime() {
    is_prime.assign(MAX + 1, true);

    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= sqrt(MAX); i++) {
        if(!is_prime[i]) {
            continue;
        }
        for(int j = i * 2; j <= MAX; j += i) {
            is_prime[j] = false;
        }
    }
}

pi solution(int n) {
    for(int i = n / 2; i >= 2; i--) {
        if(!is_prime[i]) {
            continue;
        }
        int j = n - i;
        if(is_prime[j]) {
            return { min(i, j), max(i, j)};
        }
    }
}

int main() {
    int t, n;

    set_prime();

    cin >> t;
    while(t--) {
        cin >> n;

        pi answer = solution(n);

        cout << answer.first << ' ' << answer.second << '\n';
    }
    return 0;
}