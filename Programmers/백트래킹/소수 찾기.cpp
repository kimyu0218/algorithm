#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

const int SIZE = 7;
const int MAX = 1e8 - 1;

bool visited[SIZE];
set<int> primes;
vector<bool> is_prime;

void init_is_prime() {
    is_prime.assign(MAX + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= sqrt(MAX); i++) {
        for(int j = 2 * i; j <= MAX; j += i) {
            is_prime[j] = false;
        }
    }
}

void backtracking(int idx, int len, int n, string s, string numbers) {
    if(idx == len) {
        int num = stoi(s);
        if(is_prime[num]) {
            primes.insert(num);
        }
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i]) {
            continue;
        }
        visited[i] = true;
        backtracking(idx + 1, len, n, s + numbers[i], numbers);
        visited[i] = false;
    }
}

int solution(string numbers) {
    int n = numbers.size();

    init_is_prime();

    for(int i = 1; i <= n; i++) {
        backtracking(0, i, n, "", numbers);
    }
    return primes.size();
}