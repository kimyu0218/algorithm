#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1e6;

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

vector<int> solution(int m, int n) {
    vector<int> result;
    
    set_prime();
    for(int i = m; i <= n; i++) {
        if(is_prime[i]) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    int m, n;
    
    cin >> m >> n;
    
    vector<int> result = solution(m, n);
    
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    return 0;
}