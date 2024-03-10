#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> a, vector<int> b) {
    int result = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());

    for(int i = 0; i < n; i++) {
        result += a[i] * b[i];
    }
    return result;
}

int main() {
    int n;
    vector<int> a, b;

    cin >> n;

    a.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    b.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cout << solution(n, a, b);
    return 0;
}