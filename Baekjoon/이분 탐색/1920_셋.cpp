#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, num;
    cin >> n;

    set<int> a;
    for(int i = 0; i < n; i++) {
        cin >> num;
        a.insert(num);
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> num;
        cout << (a.find(num) == a.end() ? 0 : 1) << '\n';
    }
    return 0;
}