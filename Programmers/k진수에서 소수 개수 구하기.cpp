#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

bool isPrime(ll n) { // 소수 판별
    if(n == 0 || n == 1) {
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

string decimalToNSystem(int k, int n) { // 10진법 -> k진법
    string n_system = "";
    if(n == 0) { // 0은 바로 0 반환
        return "0";
    }

    while(n > 0) {
        n_system += to_string(n % k);
        n /= k;
    }
    reverse(n_system.begin(), n_system.end());
    return n_system;
}

int solution(int n, int k) {
    int answer = 0;

    string n_digit = decimalToNSystem(k, n);
    int len = n_digit.length();
    string p = "";
    for(int i = 0; i < len; i++) {
        if(n_digit[i] == '0' && p != "") {
            answer += isPrime(stol(p));
            p = "";
            continue;
        }
        p += n_digit[i];
    }
    if(p == "") {
        return answer;
    }
    return answer + isPrime(stol(p));
}