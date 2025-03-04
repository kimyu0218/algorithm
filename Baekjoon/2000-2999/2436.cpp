#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MAX = 1000000000;

int gcd(int a, int b) { // 최대 공약수
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

vector<int> prime_fact(long long n) { // 2보다 크거나 같고 루트 n보다 작거나 같은 n의 약수
    vector<int> fact;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) fact.push_back(i);
    }
    return fact;
}

pair<int, int> find_pair(int g, int l, long long n) {
    pair<int, int> result;
    int min = MAX + MAX;

    vector<int> fact = prime_fact(n);
    for(int i = 0; i < fact.size(); i++) {
        int a = n / fact[i], b = fact[i]; // (a >= b)
        // 두 수가 최대공약수나 최소공배수를 만족하지 않는 경우
        if(g != gcd(a, b) || a * b != g * l) continue;
        // 두 수가 최대공약수나 최소공배수를 만족하고 두 수의 합이 최소인 경우
        if(a + b < min) {
            min = a+b;
            result = {b, a};
        }
    }
    return result;
}

int main() {
    int g, l;
    cin >> g >> l;

    pair<int, int> result = find_pair(g, l, (long long) g * l);
    cout << result.first << ' ' << result.second;
    return 0;
}