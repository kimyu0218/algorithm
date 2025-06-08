#include <iostream>
#include <vector>

using namespace std;

vector<int> sum;

void set_sum(vector<int> a) {
    int n = a.size();

    sum.assign(n + 1, 0);
    for(int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }
}

int solution(int i, int j) {
    return sum[j] - sum[i - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i, j;
    vector<int> a;

    cin >> n;

    a.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set_sum(a);

    cin >> m;
    while(m--) {
        cin >> i >> j;

        cout << solution(i, j) << '\n';
    }
    return 0;
}df