#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> set_prime(int n) { // 소수 세팅
    vector<int> is_prime(n+1, true);
    for(int i = 2; i <= sqrt(n); i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

vector<int> prime_list(int n) { // 소수 리스트 반환
    vector<int> list, is_prime = set_prime(n); // 소수 세팅
    for(int i = 2; i <= is_prime.size(); i++) {
        if(is_prime[i]) list.push_back(i);
    }
    return list;
}

int prime_sum(int n, vector<int> prime) {
    int ans = 0;
    // 같은 위치에서 시작하는 투 포인터 (left, right)
    int left = 0, right = 0;
    int size = (int) prime.size(), sum = prime[left];

    // 소수합이 n보다 작아도 left를 증가시키는 이유 : "연속된" 소수합을 만족하기 위함
    // left를 증가시키는 대신, 이전에 left가 가리켰던 수를 제외시켜 "연속"이라는 조건을 만족시킴
    while(left <= right && right < size) {
        if(sum == n) { // 연속된 소수합 가능
            ans++;
            if(++right == size) break;
            sum -= prime[left]; left++; // (left가 가르켰던 수) 제외
            sum += prime[right]; // (right가 새로 가리키는 수) 추가
        }
        else if(sum > n) { // n보다 큰 경우, (left가 가르켰던 수) 제외
            sum -= prime[left]; left++;
        }
        else { // n보다 작은 경우, (right가 새로 가리키는 수) 추가
            if(++right == size) break;
            sum += prime[right];
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    if(n == 1) { cout << 0; return 0; } // 1은 소수가 아니므로 곧바로 종료
    vector<int> prime = prime_list(n);
    cout << prime_sum(n, prime);
    return 0;
}