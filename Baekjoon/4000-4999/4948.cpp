#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 123456 * 2;

vector<bool> is_prime;

void set_prime() {
    is_prime.assign(MAX, true);

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

int solution(int n) {
    int answer = 0;

    for(int i = n + 1; i <= 2 * n; i++) {
        answer += is_prime[i];
    }
    return answer;
}

int main() {
    int n;

    set_prime();

    while(true) {
        cin >> n;

        if(n == 0) {
            break;
        }
        cout << solution(n) << '\n';
    }
    return 0;
}