#include <iostream>
#include <vector>

using namespace std;

int k_num(vector<bool> v, int n, int k) {
    int erase = 0;
    for(int i = 2; i <= n; i++) {
        if(!v[i]) { // 2. 가장 작은 소수 찾기
            // 3. 가장 작은 소수와 그 배수 지우기
            for(int j = i; j <= n; j += i) {
                if(v[j]) continue; // 이미 지워진 수 poss
                v[j] = true;
                if(++erase == k) return j;
            }
        }
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<bool> v;
    v.assign(n+1, false); // 1. 모든 정수 적기

    cout << k_num(v, n, k);
    return 0;
}