#include <iostream>
#include <vector>

using namespace std;
vector<int> a, sorted;

long long countSupervisor(int n, int b, int c) { // 감독관 수 세기
    long long result = 0;
    for(int i = 0; i < n; i++) {
        a[i] -= b;
        result++; // 총감독관
        if(a[i] > 0) { // 부감독관
            result += a[i]/c;
            if(a[i] % c) result++;
        }
    }
    return result;
}

int main() {
    int n, b, c;
    cin >> n;

    a.assign(n, 0);
    sorted.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> b >> c;
    cout << countSupervisor(n, b, c); // 감독관 수 세기
    return 0;
}