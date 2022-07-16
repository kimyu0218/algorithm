#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) { // 최대 공약수 구하기
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long gcd_sum(vector<int> v, int n) { // gcd 합 구하기
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++)
            sum += gcd(max(v[i], v[j]), min(v[i], v[j]));
    }
    return sum;
}

int main() {
    int t, n, x;
    cin >> t; // 테스트 케이스 입력

    while(t--) {
        cin >> n; // 각 테스트 케이스의 수의 개수

        vector<int> v;
        for(int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }
        cout << gcd_sum(v, n) << '\n';
    }
    return 0;
}