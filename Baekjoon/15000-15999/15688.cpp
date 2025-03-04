#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    vector<int> a;

    cin >> n;

    a.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}