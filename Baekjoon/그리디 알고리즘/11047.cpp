#include <iostream>
#include <vector>

using namespace std;

int solution(int k, vector<int> a) {
    int result = 0;
    int idx = a.size() - 1;

    while(k) {
        int p = k / a[idx];
        if(!p) {
            idx--;
            continue;
        }
        result += p;
        k -= p * a[idx--];
    }
    return result;
}

int main() {
    int n, k;
    vector<int> a;

    cin >> n >> k;

    a.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << solution(k, a);
    return 0;
}